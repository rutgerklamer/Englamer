#include "Englamer/Core/Renderer.h"
#include <iostream>

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
		if (scene->m_children[i] && frustum_culling(scene->get_camera(), scene->m_children[i])) {
			Entity* entity = scene->m_children[i];
			glm::mat4 mvp = scene->get_camera()->get_projection_matrix() * scene->get_camera()->get_view_matrix() * entity->get_model_matrix();
			glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
			glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), entity->mesh->get_color().x, entity->mesh->get_color().y, entity->mesh->get_color().z);
			entity->mesh->draw();
			glDrawArrays(GL_TRIANGLES, 0, entity->mesh->get_buffer_size());
		}
#ifdef _DEBUG
		if (scene->m_children[i] && frustum_culling(scene->get_debug_camera(), scene->m_children[i]))
			render_debug_mesh(scene->m_children[i], shader, scene->get_camera());
#endif _DEBUG
	}
#ifdef _DEBUG
	render_debug_camera(shader, scene->get_camera(), scene->get_camera());
	render_debug_camera(shader, scene->get_debug_camera(), scene->get_camera());
#endif _DEBUG
}

bool Renderer::frustum_culling(Camera* camera, Entity* entity)
{
	float fovy = camera->get_fov();
	float nr = camera->get_near();
	float fr = camera->get_far();

	float hheight = tan(fovy / 2.0f);
	float hwidth = hheight * 1.0f;

	glm::vec3 farright = (hwidth*fr*camera->get_right()) * (float)config::width / (float)config::height;
	glm::vec3 fartop = (hheight*fr*camera->get_up());
	glm::vec3 nearright = (hwidth*nr*camera->get_right()) * (float)config::width / (float)config::height;
	glm::vec3 neartop = (hheight*nr*camera->get_up());
	glm::vec3 center = camera->position + fr*camera->get_front();
	glm::vec3 nearcenter = camera->position + nr*-camera->get_front();

	glm::vec3 ftl = center - farright + fartop; //far top left
	glm::vec3 fbr = center + farright - fartop; //far bottom right
	glm::vec3 ftr = center + farright + fartop; //far bottom right
	glm::vec3 fbl = center - farright - fartop; //far bottom right
	glm::vec3 ntl = nearcenter - nearright + neartop; //far top left
	glm::vec3 nbr = nearcenter + nearright - neartop; //far bottom right
	glm::vec3 ntr = nearcenter + nearright + neartop; //far bottom right
	glm::vec3 nbl = nearcenter - nearright - neartop; //far bottom right

	glm::vec3 min = entity->mesh->m_mesh_data.min;
	glm::vec3 max = entity->mesh->m_mesh_data.max;
	glm::vec3 pos = entity->position;
	glm::vec3 boxnearbottomleft = min + pos;
	glm::vec3 boxnearbottomright = glm::vec3(-min.x, min.y, min.z)+pos;
	glm::vec3 boxneartopright =  glm::vec3(-min.x, -min.y, min.z) + pos;
	glm::vec3 boxneartopleft = glm::vec3(min.x, -min.y, min.z) + pos;
	glm::vec3 boxfartopright = max + pos;
	glm::vec3 boxfartopleft = glm::vec3(-max.x, max.y, max.z) + pos;
	glm::vec3 boxfarbottomleft =  glm::vec3(-max.x, -max.y, max.z) + pos;
	glm::vec3 boxfarbottomright =  glm::vec3(max.x, -max.y, max.z) + pos;

	// FAR 
	glm::vec3 v = ftr - ftl;
	glm::vec3 u = fbr - ftl;
	glm::vec3 n = glm::cross(v, u);
	double D = -glm::dot(n, ftl);
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D > 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D > 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D > 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D > 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D > 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D > 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D > 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D > 0)
		return false;

	// NEAR
	v = ntr - ntl;
	u = nbr - ntl;
	n = glm::cross(v, u);
	D = -glm::dot(n, ntl); 
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D < 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D < 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D < 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D < 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D < 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D < 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D < 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D < 0)
		return false;

	// TOP
	v = ftr - ftl;
	u = ntr - ftl;
	n = glm::cross(v, u);
	D = -glm::dot(n, ftl);
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D < 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D < 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D < 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D < 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D < 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D < 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D < 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D < 0)
		return false;

	// BOTTOM
	v = fbr - fbl;
	u = nbr - fbl;
	n = glm::cross(v, u);
	D = -glm::dot(n, fbl);
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D > 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D > 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D > 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D > 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D > 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D > 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D > 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D > 0)
		return false;

	// RIGHT
	v = fbr - nbr;
	u = ntr - nbr;
	n = glm::cross(v, u);
	D = -glm::dot(n, nbr);
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D > 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D > 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D > 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D > 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D > 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D > 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D > 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D > 0)
		return false;

	// LEFT
	v = fbl - nbl;
	u = ntl - nbl;
	n = glm::cross(v, u);
	D = -glm::dot(n, nbl);
	if (n.x*boxnearbottomleft.x + n.y*boxnearbottomleft.y + n.z*boxnearbottomleft.z + D < 0 && n.x*boxnearbottomright.x + n.y*boxnearbottomright.y + n.z*boxnearbottomright.z + D < 0 &&
		n.x*boxneartopright.x + n.y*boxneartopright.y + n.z*boxneartopright.z + D < 0 && n.x*boxneartopleft.x + n.y*boxneartopleft.y + n.z*boxneartopleft.z + D < 0 &&
		n.x*boxfarbottomleft.x + n.y*boxfarbottomleft.y + n.z*boxfarbottomleft.z + D < 0 && n.x*boxfarbottomright.x + n.y*boxfarbottomright.y + n.z*boxfarbottomright.z + D < 0 &&
		n.x*boxfartopright.x + n.y*boxfartopright.y + n.z*boxfartopright.z + D < 0 && n.x*boxfartopleft.x + n.y*boxfartopleft.y + n.z*boxfartopleft.z + D < 0)
		return false;

	return true;
}

#ifdef _DEBUG
void Renderer::render_debug_mesh(Entity* entity, Shader* shader, Camera* camera)
{
	shader->Use();
	glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * entity->get_model_matrix();
	glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
	if (frustum_culling(camera, entity))
		glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 0, 1, 0);
	else
		glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 1, 0, 0);
	render_debug_set_boundaries(entity->mesh->m_mesh_data.min, entity->mesh->m_mesh_data.max);
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
		glm::mat4 mvp = render_camera->get_projection_matrix() * render_camera->get_view_matrix() * m;
		glUniformMatrix4fv(glGetUniformLocation(shader->shaderProgram, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
		glUniform3f(glGetUniformLocation(shader->shaderProgram, "color"), 1, 0, 0);
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
	glm::vec3 center = glm::vec3(1, 1, 1) + fr*camera->get_front();

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
