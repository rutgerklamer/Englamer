#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	for (int i = 0; i < 30; i++)
	{
		Player* p = new Player();
		p->position.x = sin(i) * 25.0f;
		p->position.z = cos(i) * 25.0f;
		add_child(p);
	}
}

Scene1::~Scene1()
{
	cleanup();
}

void Scene1::update(float dt)
{
	get_debug_camera()->process_mouse_movement(1.0f, 0);
	if (Input::get_key(GLFW_KEY_D))
		get_camera()->position += get_camera()->get_right() / 100.0f;
	if (Input::get_key(GLFW_KEY_A))
		get_camera()->position -= get_camera()->get_right() / 100.0f;
	if (Input::get_key(GLFW_KEY_W))
		get_camera()->position += get_camera()->get_front() / 100.0f;
	if (Input::get_key(GLFW_KEY_S))
		get_camera()->position -= get_camera()->get_front() / 100.0f;
	if (Input::get_key(GLFW_KEY_Q))
		get_camera()->position += get_camera()->get_up() / 100.0f;
	if (Input::get_key(GLFW_KEY_Z))
		get_camera()->position -= get_camera()->get_up() / 100.0f;
}