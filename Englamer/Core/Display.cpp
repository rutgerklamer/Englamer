#include "Englamer/Core/Display.h"

GLFWwindow* Display::m_window;

Display::Display()
{
	create_context();
}

Display::~Display()
{

}

void Display::create_context()
{
	//Check if glfw is working
	if (!glfwInit())
		std::cout << "glfw is not supported!" << std::endl;

	// Set the openGL version, MAJOR.MINOR
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, config::major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, config::minor);
	//For Linux and Mac OS
	#if !defined(_WIN32) && !defined(WIN32)
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
	//Create the window
	m_window = glfwCreateWindow(config::width, config::height, config::window_name.c_str(), nullptr, nullptr);

	//Check if the window was created succesfully
	if (m_window)
	{
		// Make the window available for openGL
		glfwMakeContextCurrent(m_window);
		// Set glew experimental
		glewExperimental = GL_TRUE;

		//Initialize GLEW
		if (glewInit() != GLEW_OK)
			std::cout << "Failed to initialize GLEW" << std::endl;

		//Enable depth testing
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		//Set input
		glfwSetKeyCallback(m_window, Input::input.key_callback);
		glfwSetCursorPosCallback(m_window, Input::input.mouse_callback);
		glfwSetMouseButtonCallback(m_window, Input::input.mouse_button_callback);
		//Enable backface culling
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
	}

	// If user set the mouse to be locked, lock the mouse
	if (config::mouse_lock)
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Display::update()
{
	// Clear the window and the depth buffer so the window is empty when we try to render to it
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// We declared the color information in the config header, we can't acces it directly so we use a vec4 color
	glm::vec4 color = config::clear_color;
	// Set the clear color
	glClearColor(color.x, color.y, color.z, color.w);
}

void Display::late_update()
{
	// Swap buffers
	glfwSwapBuffers(m_window);
	// Update the windows input
	glfwPollEvents();
}
