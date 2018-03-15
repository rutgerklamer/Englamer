#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	for (int i = 0; i < 100; i++)
	{
		Player* p = new Player();
		p->position.x = sin(i) * i/3.0f;
		p->position.z = cos(i) * i/3.0f;
		add_child(p);
	}
}

Scene1::~Scene1()
{
	cleanup();
}

void Scene1::update(float dt)
{
	get_debug_camera()->process_mouse_movement(10.0f, 0);
	if (Input::get_key(GLFW_KEY_D))
		get_camera()->position += get_camera()->get_right() / 10.0f;
	if (Input::get_key(GLFW_KEY_A))
		get_camera()->position -= get_camera()->get_right() / 10.0f;
	if (Input::get_key(GLFW_KEY_W))
		get_camera()->position += get_camera()->get_front() / 10.0f;
	if (Input::get_key(GLFW_KEY_S))
		get_camera()->position -= get_camera()->get_front() / 10.0f;
	if (Input::get_key(GLFW_KEY_Q))
		get_camera()->position += get_camera()->get_up() / 10.0f;
	if (Input::get_key(GLFW_KEY_Z))
		get_camera()->position -= get_camera()->get_up() / 10.0f;
}