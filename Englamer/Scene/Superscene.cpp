#include "Englamer/Scene/Superscene.h"

Superscene::Superscene()
{
	m_camera = new Camera();
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
		get_debug_camera()->position += get_debug_camera()->get_right() / 100.0f;
	if (Input::get_key(GLFW_KEY_LEFT))
		get_debug_camera()->position -= get_debug_camera()->get_right() / 100.0f;
	if (Input::get_key(GLFW_KEY_UP))
		get_debug_camera()->position += get_debug_camera()->get_front() / 100.0f;
	if (Input::get_key(GLFW_KEY_DOWN))
		get_debug_camera()->position -= get_debug_camera()->get_front() / 100.0f;
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
	for (int i = 0; i < m_children.size(); i++) {
		m_children[i]->update(dt);
	}
}
