#include "Englamer/Core/Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch, glm::vec3 front)
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

	this->frustum = new Frustum();
	frustum->calculate_frustum(this->right, this->up, this->front, this->position, this->zoom, this->zNear, this->zFar);
}

Camera::~Camera()
{

}

glm::mat4 Camera::get_view_matrix()
{
	return glm::lookAt(this->position, this->position + this->front, this->up);
}

void Camera::process_mouse_movement(float xOffset, float yOffset, bool constrainPitch)
{
	xOffset *= 0.05;
	yOffset *= 0.05;
	this->yOff += yOffset;
	this->xOff += xOffset;
	this->yaw += xOffset;
	this->pitch += yOffset;

	if (constrainPitch)
	{
		if (this->pitch >= 89.0f)
		{
			this->pitch = 89.0f;
			this->yOff = 89.0f;
		}
		else if (this->pitch <= -89.0f)
		{
			this->pitch = -89.0f;
			this->yOff = -89.0f;
		}
	}
	frustum->calculate_frustum(this->right, this->up, this->front, this->position, this->zoom, this->zNear, this->zFar);
	this->update_camera_vector();
}

void Camera::update()
{
	if (last_position != position)
		frustum->calculate_frustum(this->right, this->up, this->front, this->position, this->zoom, this->zNear, this->zFar);
	last_position = position;
}

void Camera::update_camera_vector()
{
	glm::vec3 f;
	f.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	f.y = sin(glm::radians(this->pitch));
	f.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->front = glm::normalize(f);

	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->front));
}

glm::vec3 Camera::get_right()
{
	return this->right;
}

glm::vec3 Camera::get_front()
{
	return this->front;
}

glm::vec3 Camera::get_up()
{
	return this->up;
}

glm::mat4 Camera::get_model_matrix()
{
	glm::mat4 modelmatrix;
	modelmatrix = glm::translate(modelmatrix, glm::vec3(2, 2, 2));
	return modelmatrix*glm::toMat4(glm::quat(glm::radians(glm::vec3(pitch, yaw, 0))));
}

void Camera::set_near_far(float n, float f)
{
	this->zNear = n;
	this->zFar = f;
}

float Camera::get_near()
{
	return this->zNear;
}

float Camera::get_far()
{
	return this->zFar;
}

float Camera::get_fov()
{
	return this->zoom;
}


glm::mat4 Camera::get_projection_matrix()
{
	return glm::perspective(this->zoom, (float)config::width / (float)config::height, zNear, zFar);
}

void Camera::process_mouse_croll(float yOffset)
{
	if (this->zoom >= 1.0f && this->zoom <= 45.0f)
		this->zoom -= yOffset;
	if (this->zoom <= 1.0f)
		this->zoom = 1.0f;
	if (this->zoom >= 45.0f)
		this->zoom = 45.0f;
	frustum->calculate_frustum(this->right, this->up, this->front, this->position, this->zoom, this->zNear, this->zFar);
}

bool Camera::is_in_frustum(Entity* e)
{
	return this->frustum->is_in_frustum(e);
}
