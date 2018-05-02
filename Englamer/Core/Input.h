#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Englamer/Core/Config.h"
#include "Englamer/Core/Camera.h"

class Input
{
public:
	/**
	* Called by glfw, We handle the input by setting the array of keys,
	* To true or false according to the action
	*/
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	/**
	* Called by glfw, We handle the input by setting the array of mouse button keys,
	* To true or false according to the action
	*/
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	/**
	* Called by glfw, We handle the input by calculating difference between lastY and lastX,
	*/
	static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	/**
	* Return the position of the mouse in the window
	*/
	static glm::vec2 get_mouse_position();
	/**
	* Set the pointer of the camera of the scene to the pointer in input
	* Takes in a camera pointer, this is the camera you want to set
	*/
	static void set_camera(Camera* camera);
	/**
	* Update loop
	* Takes in a float deltaTime, you probably want to use this
	*/
	static void update(float deltaTime);

	static Input input;
	static bool get_key(int k) { return (k>=0 && k<=1024 ? input.keys[k] : false); }
	static bool get_key_down(int k) { return (k>=0 && k<=1024 ? input.keysDown[k] : false); }
	static bool get_key_up(int k) { return (k>=0 && k<=1024 ? input.keysUp[k] : false); }
	static bool get_mouse_key(int k) { return (k>=0 && k<=7 ? input.mouseKeys[k] : false); }
	static bool get_mouse_key_down(int k) { return (k>=0 && k<=7 ? input.mouseKeysDown[k] : false); }
	static bool get_mouse_key_up(int k) { return (k>=0 && k<=7 ? input.mouseKeysUp[k] : false); }
private:
	void set_window(GLFWwindow* window);
	glm::vec2 lastMouse;
	glm::vec2 currentMouse;
	bool keys[1024];
	bool keysDown[1024];
	bool keysUp[1024];
	bool mouseKeys[7];
	bool mouseKeysDown[7];
	bool mouseKeysUp[7];
	bool firstMouse;
	float lastX;
	float lastY;
	float currentX;
	float currentY;
	Camera* camera;
	GLFWwindow* window;
};

#endif // INPUT_H
