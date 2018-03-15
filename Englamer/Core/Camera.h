#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <iostream>

#include "Englamer/Core/Config.h"
#include "Englamer/Utils/Frustum.h"

class Camera
{
public:
	/**
	* Either set the it automatically or set it manual
	* /see Camera::Camera()
	*/
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f, glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f));
	/**
	* Destructor
	*/
	~Camera();
	/**
	* Return the view matrix
	*/
	glm::mat4 get_view_matrix();
	/**
	* Return the projection or ortho matrix, depending on the orthographic state
	*/
	glm::mat4 get_projection_matrix();
	/**
	* Change the yaw and pitch of the camera according to mouse movement
	* Takes in the X and Y offset of the mouse calculated by,
	* /see Input::processMouseMovement()
	*/
	void process_mouse_movement(float xOffset, float yOffset, bool constrainPitch = true);
	/**
	* Set the zoom (FOV) of the camera
	* Takes in the difference calculated by
	* /see Input::processMouseScroll()
	*/
	void process_mouse_croll(float yOffset);
	/**
	* Calculate the new front of the camera according to
	* The pitch and yaw
	*/
	void update_camera_vector();
	glm::vec3 get_right();
	glm::vec3 get_front();
	glm::vec3 get_up();
	glm::mat4 get_model_matrix();
	void set_near_far(float n, float f);
	float get_near();
	float get_far();
	float get_fov();

	glm::vec3 position;
private:
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	float yaw;
	float pitch;
	float movementSpeed;
	float mouseSensitivity;
	float zoom;
	float zFar;
	float zNear;

	float xOff, yOff;
};

#endif CAMERA_H