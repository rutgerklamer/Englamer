#include "Englamer/Core/Renderer.h"

Renderer::Renderer()
{
	m_debug_mesh = new Mesh();
	m_debug_mesh->make_box();
}

Renderer::~Renderer()
{

}

void Renderer::render_scene(Superscene* scene, Shader* shader)
{
	shader->Use();
	for (int i = 0; i < scene->m_children.size(); i++) {
		if (scene->m_children[i] != NULL && scene->m_children[i]->get_component(MESH) != NULL && scene->m_children[i]->get_component(MESH)->get_enabled() && scene->get_camera()->is_in_frustum(scene->m_children[i])) {
			Entity* entity = scene->m_children[i];
			glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(((Transform*)entity->get_component(TRANSFORM))->get_model_matrix()));
			glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(scene->get_camera()->get_view_matrix()));
			glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(scene->get_camera()->get_projection_matrix()));
			if (entity->get_component(MATERIAL) != NULL)
				glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), ((Material*)entity->get_component(MATERIAL))->get_color().x, ((Material*)entity->get_component(MATERIAL))->get_color().y, ((Material*)entity->get_component(MATERIAL))->get_color().z);
			else
				glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 0,0,0);
			((Mesh*)entity->get_component(MESH))->draw();
			glDrawArrays(GL_TRIANGLES, 0, ((Mesh*)entity->get_component(MESH))->get_buffer_size());
#ifdef _DEBUG
			glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 1,0,0);
			glDrawArrays(GL_LINE_STRIP, 0, ((Mesh*)entity->get_component(MESH))->get_buffer_size());
#endif _DEBUG
		}
#ifdef _DEBUG
		if (scene->m_children[i] && scene->m_children[i]->get_component(MESH) && scene->get_debug_camera()->is_in_frustum(scene->m_children[i]))
			render_debug_mesh(scene->m_children[i], shader, scene->get_camera());
#endif _DEBUG
	}
#ifdef _DEBUG
	render_debug_camera(shader, scene->get_camera(), scene->get_camera());
	render_debug_camera(shader, scene->get_debug_camera(), scene->get_camera());
#endif _DEBUG
}

#ifdef _DEBUG
void Renderer::render_debug_mesh(Entity* entity, Shader* shader, Camera* camera)
{
	shader->Use();
	glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(((Transform*)entity->get_component(TRANSFORM))->get_model_matrix()));
	glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(camera->get_view_matrix()));
	glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(camera->get_projection_matrix()));
	glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 1, 0, 0);
	render_debug_set_boundaries(((Mesh*)entity->get_component(MESH))->m_mesh_data.min, ((Mesh*)entity->get_component(MESH))->m_mesh_data.max);
	m_debug_mesh->bind();
	m_debug_mesh->draw();
	glDrawArrays(GL_LINE_LOOP, 0, m_debug_mesh->get_buffer_size());
}

void Renderer::render_debug_camera(Shader* shader, Camera* camera, Camera* render_camera)
{
	shader->Use();
	std::vector<glm::vec4> positions;
	positions = render_debug_calculate_frustum_planes(camera);
	for (int i = 0; i < positions.size(); i++) {
		glm::mat4 m;
		m = glm::translate(m, glm::vec3(positions[i].x, positions[i].y, positions[i].z));
		m = glm::scale(m, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(m));
		glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(camera->get_view_matrix()));
		glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(camera->get_projection_matrix()));
		glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 0, 0, 1);
		m_debug_mesh->draw();
		glDrawArrays(GL_LINE_STRIP, 0, m_debug_mesh->get_buffer_size());
	}
}

std::vector<glm::vec4> Renderer::render_debug_calculate_frustum_planes(Camera* camera)
{
	float fovy = camera->get_fov();
	float nr = camera->get_near();
	float fr = camera->get_far();

	float hheight = tan(fovy / 2);
	float hwidth = hheight * 1.0f;

	glm::vec3 farright = (hwidth*fr*camera->get_right()) * (float)config::width / (float)config::height;
	glm::vec3 fartop = hheight*fr*camera->get_up();
	glm::vec3 nearright = (hwidth*nr*camera->get_right()) * (float)config::width / (float)config::height;
	glm::vec3 neartop = hheight*nr*camera->get_up();
	glm::vec3 center = glm::vec3(0, 0, 0) + fr*camera->get_front();

	glm::vec3 ftl = center - farright + fartop; //far top left
	glm::vec3 fbr = center + farright - fartop; //far bottom right
	glm::vec3 ftr = center + farright + fartop; //far bottom right
	glm::vec3 fbl = center - farright - fartop; //far bottom right
	glm::vec3 ntl = center - nearright + neartop; //far top left
	glm::vec3 nbr = center + nearright - neartop; //far bottom right
	glm::vec3 ntr = center + nearright + neartop; //far bottom right
	glm::vec3 nbl = center - nearright - neartop; //far bottom right

	std::vector<glm::vec4> posa;
	posa.push_back(glm::vec4(glm::normalize(ftl) * 10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(fbr) * 10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(ftr) * 10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(fbl) * 10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(ntl) * -10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(nbr) * -10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(ntr) * -10.0f + camera->position, 1));
	posa.push_back(glm::vec4(glm::normalize(nbl) * -10.0f + camera->position, 1));
	return posa;
}
#endif _DEBUG

void Renderer::render_debug_set_boundaries(glm::vec3 min, glm::vec3 max)
{

	for (int i = 0; i < m_debug_mesh->m_mesh_data.vertices.size(); i++) {
		if (m_debug_mesh->m_mesh_data.vertices[i].x < 0)
			m_debug_mesh->m_mesh_data.vertices[i].x = min.x - 0.1f;
		if (m_debug_mesh->m_mesh_data.vertices[i].y < 0)
			m_debug_mesh->m_mesh_data.vertices[i].y = min.y - 0.1f;
		if (m_debug_mesh->m_mesh_data.vertices[i].z < 0)
			m_debug_mesh->m_mesh_data.vertices[i].z = min.z - 0.1f;

		if (m_debug_mesh->m_mesh_data.vertices[i].x > 0)
			m_debug_mesh->m_mesh_data.vertices[i].x = max.x + 0.1f;
		if (m_debug_mesh->m_mesh_data.vertices[i].y > 0)
			m_debug_mesh->m_mesh_data.vertices[i].y = max.y + 0.1f;
		if (m_debug_mesh->m_mesh_data.vertices[i].z > 0)
			m_debug_mesh->m_mesh_data.vertices[i].z = max.z + 0.1f;
	}
}
