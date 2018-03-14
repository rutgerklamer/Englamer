#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <iostream>

#include "Englamer/Core/Camera.h"

class Camera
{
public:
	/**
	* Either set the it automatically or set it manual
	* /see Camera::Camera()
	*/
	Camera(glm::vec3 position = glm::vec3(0.01f, 0.01f, 0.01f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f, glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f))
	{
		this->position = position;
		this->worldUp = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->update_camera_vector();

		this->zoom = 45.0f;
		this->mouseSensitivity = 0.05f;
		this->movementSpeed = 4.0f;

		this->zFar = 1000.0f;
		this->zNear = 0.1f;

		this->yOff = 0;
		this->xOff = 0;
	}
	/**
	* Destructor
	*/
	virtual ~Camera()
	{

	}
	/**
	* Return the view matrix
	*/
	glm::mat4 get_view_matrix()
	{
		return glm::lookAt(this->position, this->position + this->front, this->up);
	}
	/**
	* Return the projection or ortho matrix, depending on the orthographic state
	*/
	glm::mat4 get_projection_matrix()
	{
		return glm::perspective(this->zoom, (float)config::width / (float)config::height, zNear, zFar);
	}
	/**
	* Change the yaw and pitch of the camera according to mouse movement
	* Takes in the X and Y offset of the mouse calculated by,
	* /see Input::processMouseMovement()
	*/
	void process_mouse_movement(float xOffset, float yOffset, bool constrainPitch = true)
	{
		xOffset *= 0.05;
		yOffset *= 0.05;
		yOff += yOffset;
		xOff += xOffset;
		this->yaw += xOffset;
		this->pitch += yOffset;

		if (constrainPitch)
		{
			if (this->pitch >= 89.0f)
			{
				this->pitch = 89.0f;
				yOff = 89.0f;
			}
			else if (this->pitch <= -89.0f)
			{
				this->pitch = -89.0f;
				yOff = -89.0f;
			}
		}
		this->update_camera_vector();
	}
	/**
	* Set the zoom (FOV) of the camera
	* Takes in the difference calculated by
	* /see Input::processMouseScroll()
	*/
	void process_mouse_croll(float yOffset)
	{
		if (this->zoom >= 1.0f && this->zoom <= 45.0f)
			this->zoom -= yOffset;
		if (this->zoom <= 1.0f)
			this->zoom = 1.0f;
		if (this->zoom >= 45.0f)
			this->zoom = 45.0f;
	}
	/**
	* Calculate the new front of the camera according to
	* The pitch and yaw
	*/
	void update_camera_vector()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		front.y = sin(glm::radians(this->pitch));
		front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

		this->front = glm::normalize(front);

		this->right = glm::normalize(glm::cross(this->front, this->worldUp));
		this->up = glm::normalize(glm::cross(this->right, this->front));
	}

	glm::vec3 get_right()
	{
		return this->right;
	}

	glm::vec3 get_front()
	{
		return this->front;
	}

	glm::vec3 get_up()
	{
		return this->up;
	}

	glm::mat4 get_model_matrix()
	{
		glm::mat4 modelmatrix;
		modelmatrix = glm::translate(modelmatrix, glm::vec3(2,2,2));
		return modelmatrix*glm::toMat4(glm::quat(glm::radians(glm::vec3(pitch, yaw, 0))));
	}

	void set_near_far(float n, float f)
	{
		this->zNear = n;
		this->zFar = f;
	}

	float get_near()
	{
		return this->zNear;
	}

	float get_far()
	{
		return this->zFar;
	}

	float get_fov()
	{
		return this->zoom;
	}

	glm::vec3 position;
protected:
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

#endif // CAMERA_H