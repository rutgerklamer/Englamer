#include "Englamer/Components/Transform.h"

Transform::Transform() : Component()
{
	set_component_type(TRANSFORM);
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
	position = glm::vec3(0, 0, 0);
}

Transform::~Transform()
{

}

glm::mat4 Transform::get_model_matrix()
{
	return get_position_matrix()*get_scale_matrix()*get_rotation_matrix();
}

glm::mat4 Transform::get_position_matrix()
{
	glm::mat4 modelmatrix;
	modelmatrix = glm::translate(modelmatrix, position);
	return modelmatrix;
}

glm::mat4 Transform::get_scale_matrix()
{
	glm::mat4 modelmatrix;
	modelmatrix = glm::scale(modelmatrix, scale);
	return modelmatrix;
}

glm::mat4 Transform::get_rotation_matrix()
{
	return glm::toMat4(glm::quat(rotation));
}
