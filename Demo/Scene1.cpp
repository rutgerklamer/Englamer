#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	for (int i = 0; i < 10; i++)
	{
			Player* p = new Player();
			((Transform*)p->get_component(TRANSFORM))->position.x = sin(i) * 10.0f;
			((Transform*)p->get_component(TRANSFORM))->position.z = cos(i) * 10.0f;
			add_child(p);
	}
	sl = new SceneLight();
	add_child(sl);
}

Scene1::~Scene1()
{
	cleanup();
}

void Scene1::update(float dt)
{
	int objects_in_view = 0;
	for (int i = 0; i < m_children.size(); i++) {
	//	((Transform*)m_children[i]->get_component(TRANSFORM))->position.x = sin(i + glfwGetTime()) * 10.0f;
	//	((Transform*)m_children[i]->get_component(TRANSFORM))->position.z = cos(i + glfwGetTime()) * 10.0f;
	}
#ifdef _DEBUG
	//get_debug_camera()->process_mouse_movement(5.0f * dt * 100.0f, 0);
#endif _DEBUG
	if (Input::get_key(GLFW_KEY_D))
		get_camera()->position += get_camera()->get_right() * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_A))
		get_camera()->position -= get_camera()->get_right() * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_W))
		get_camera()->position += get_camera()->get_front() * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_S))
		get_camera()->position -= get_camera()->get_front() * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_Q))
		get_camera()->position += get_camera()->get_up() * dt * 30.0f;
	if (Input::get_key(GLFW_KEY_Z))
		get_camera()->position -= get_camera()->get_up() * dt * 30.0f;
}
