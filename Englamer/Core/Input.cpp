#include "Englamer/Core/Input.h"

Input Input::input;

void Input::set_window(GLFWwindow* window)
{
	window = window;
}

void Input::update(float deltaTime)
{
	for (unsigned int i = 0; i < 1024; i++) {
		input.keysDown[i] = false;
		input.keysUp[i] = false;
	}
	for (unsigned int i = 0; i < 7; i++) {
		input.mouseKeysDown[i] = false;
		input.mouseKeysUp[i] = false;
	}
}

void Input::set_camera(Camera* camera)
{
	input.camera = camera;
}


Camera* Input::get_camera()
{
	return input.camera;
}

glm::vec2 Input::get_window_size()
{
	int width;
	int height;
	glfwGetWindowSize(input.window, &width, &height);
	return glm::vec2(width, height);
}

glm::vec2 Input::get_mouse_position()
{
	double dx, dy;
	glfwGetCursorPos(input.window, &dx, &dy);

	float x = dx;
	float y = dy;

	glm::vec2 mousepos;
	mousepos.x = x;
	mousepos.y = y;
	input.currentMouse = mousepos;
	return mousepos;
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key >= 0 && key < config::width) {
		if (GLFW_PRESS == action) {
			input.keys[key] = true;
			input.keysDown[key] = true;
		}
		else if (GLFW_RELEASE == action) {
			input.keys[key] = false;
			input.keysUp[key] = true;
		}
	}
}

void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action) {
		input.mouseKeys[button] = true;
		input.mouseKeysDown[button] = true;
	}
	else {
		input.mouseKeys[button] = false;
		input.mouseKeysUp[button] = true;
	}
}

void Input::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	if (input.firstMouse) {
		input.lastX = xPos;
		input.lastY = yPos;
		input.firstMouse = false;
	}
	input.lastX = input.currentX;
	input.lastY = input.currentY;
	GLfloat xOffset = xPos - input.currentX;
	GLfloat yOffset = input.currentY - yPos;

	input.currentX = xPos;
	input.currentY = yPos;
	input.camera->process_mouse_movement(xOffset, yOffset);
}
