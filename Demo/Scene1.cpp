#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	this->add_skybox("Assets/posx.jpg", "Assets/negx.jpg", "Assets/posy.jpg", "Assets/negy.jpg", "Assets/posz.jpg", "Assets/negz.jpg");
	for (int i = 0; i < 6; i++)
	{
			Player* p = new Player();
			((Transform*)p->get_component(TRANSFORM))->position.x = sin(i) * 15.0f;
			((Transform*)p->get_component(TRANSFORM))->position.z = cos(i) * 15.0f;
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
