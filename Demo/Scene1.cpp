#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	for (int i = 0; i < 100; i++)
	{
		Player* p = new Player();
		((Transform*)p->get_component(TRANSFORM))->position.x = sin(i) * i;
		((Transform*)p->get_component(TRANSFORM))->position.z = cos(i) * i ;
		add_child(p);
	}
}

Scene1::~Scene1()
{
	cleanup();
}

void Scene1::update(float dt)
{
	int objects_in_view = 0;
	for (int i = 0; i < m_children.size(); i++) {
		if (get_camera()->is_in_frustum(m_children[i])) {
			objects_in_view++;
		}
		}
	std::cout << "OBJECTS IN VIEW: " << objects_in_view << std::endl;
#ifdef _DEBUG
	get_debug_camera()->process_mouse_movement(50.0f, 0);
#endif _DEBUG
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
