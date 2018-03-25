#include "Englamer/Scene/Superscene.h"

Superscene::Superscene()
{
	shader = new Shader("Data/Shaders/shader.vs", "Data/Shaders/shader.fs");
	m_camera = new Camera();
	m_skybox = NULL;
#ifdef _DEBUG
	m_debug_camera = new Camera();
# endif _DEBUG
}

Superscene::~Superscene()
{

}

void Superscene::cleanup()
{
	for (int i = 0; i < m_children.size(); i++)
		delete m_children[i];
	delete m_camera;
#ifdef _DEBUG
	delete m_debug_camera;
#endif _DEBUG
}

void Superscene::add_child(Entity* entity)
{
	this->m_children.push_back(entity);
	if (entity->get_component(LIGHT) != NULL)
		this->m_lights.push_back(entity);
}

void Superscene::remove_child(Entity* entity)
{
	for (int i = 0; i < m_children.size(); i++) {
		if (m_children[i] == entity) {
			m_children.erase(m_children.begin() + i);
			return;
		}
	}

}

Camera* Superscene::get_camera()
{
	return this->m_camera;
}

void Superscene::update(float dt)
{
	// For linking reasons
}


#ifdef _DEBUG
Camera* Superscene::get_debug_camera()
{
	return this->m_debug_camera;
}

void Superscene::debug_update(float dt)
{
	if (Input::get_key(GLFW_KEY_RIGHT))
		get_debug_camera()->position += get_debug_camera()->get_right()  * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_LEFT))
		get_debug_camera()->position -= get_debug_camera()->get_right()  * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_UP))
		get_debug_camera()->position += get_debug_camera()->get_front()  * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_DOWN))
		get_debug_camera()->position -= get_debug_camera()->get_front()  * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_I))
		get_debug_camera()->process_mouse_movement(0, 1);
	if (Input::get_key(GLFW_KEY_K))
		get_debug_camera()->process_mouse_movement(0, -1);
	if (Input::get_key(GLFW_KEY_J))
		get_debug_camera()->process_mouse_movement(-1, 0);
	if (Input::get_key(GLFW_KEY_L))
		get_debug_camera()->process_mouse_movement(1, 0);
}
#endif _DEBUG

void Superscene::update_children(float dt)
{
	get_camera()->update();
#ifdef _DEBUG
	get_debug_camera()->update();
#endif _DEBUG
	for (int i = 0; i < m_children.size(); i++) {
		m_children[i]->engine_update(dt);
		m_children[i]->update(dt);
		for (int j = 0; j < m_children.size(); j++) {
			if (m_children[i] != m_children[j] && m_children[i] != NULL && m_children[i]->get_component(COLLIDER) != NULL && m_children[j] != NULL && m_children[j]->get_component(COLLIDER) != NULL)
			{
				if (Intersect::intersectAABB(m_children[i], m_children[j])) {
					m_children[i]->collision(m_children[j]);
					m_children[j]->collision(m_children[i]);
				}
			}
		}
	}
}

void Superscene::add_skybox(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front)
{
	if (m_skybox != NULL)
		remove_skybox();
	m_skybox = new Skybox(right, left, up, down, back, front);

  shader->Use();
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, m_skybox->get_cubemap());
  glUniform1i(glGetUniformLocation(shader->shaderProgram, "skybox"), 0);
}

void Superscene::remove_skybox()
{
	delete m_skybox;
	m_skybox = NULL;
}

Skybox* Superscene::get_skybox()
{
	return m_skybox;
}

Shader* Superscene::get_shader()
{
	return this->shader;
}

void Superscene::load_shader(const char* vp, const char* fp)
{
	delete shader;
	shader = new Shader(vp, fp);
}
