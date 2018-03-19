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
	glm::mat4 modelmatrix;
	modelmatrix = glm::translate(modelmatrix, position);
	modelmatrix = glm::scale(modelmatrix, scale);
	return modelmatrix*glm::toMat4(glm::quat(rotation));
}

