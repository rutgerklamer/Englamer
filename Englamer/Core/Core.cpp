#include "Englamer/Core/Core.h"

Core::Core()
{
	config::read_config("Data/Settings/settings.ini");
	m_display = new Display();
}

Core::~Core()
{
	delete m_display;
}

void Core::init()
{
	Input::input.set_camera(m_scenemanager.get_scene()->get_camera());
	// TODO Move to display asap.
	glfwSetKeyCallback(Display::m_window, Input::input.key_callback);
	glfwSetCursorPosCallback(Display::m_window, Input::input.mouse_callback);
	glfwSetMouseButtonCallback(Display::m_window, Input::input.mouse_button_callback);

	renderer = new Renderer();
}

void Core::run()
{
	do {
		time.update();
		m_scenemanager.get_scene()->update(time.get_deltatime());
		m_scenemanager.get_scene()->update_children(time.get_deltatime());
		m_display->update();
		renderer->render_scene(m_scenemanager.get_scene(), m_scenemanager.get_scene()->get_shader());
#ifdef _DEBUG
		m_scenemanager.get_scene()->debug_update(time.get_deltatime());
#endif _DEBUG
		m_display->late_update();
	} while (!glfwWindowShouldClose(Display::m_window));
}

void Core::add_scene(Superscene* scene)
{
	m_scenemanager.add_scene(scene);
}
