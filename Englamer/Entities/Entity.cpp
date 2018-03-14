#include "Englamer/Entities/Entity.h"

Entity::Entity()
{
	mesh = new Mesh();
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}

Entity::~Entity()
{

}

glm::mat4 Entity::get_model_matrix()
{
		glm::mat4 modelmatrix;
		modelmatrix = glm::translate(modelmatrix, position);
		modelmatrix = glm::scale(modelmatrix, scale);
		return modelmatrix*glm::toMat4(glm::quat(rotation));
}

glm::mat4 Entity::get_rotation_matrix()
{
	return glm::toMat4(glm::quat(rotation));
}

glm::mat4 Entity::get_scale_matrix()
{
	glm::mat4 scalematrix;
	scalematrix = glm::scale(scalematrix, scale);
	return scalematrix;
}

glm::mat4 Entity::get_position_matrix()
{
	glm::mat4 positionmatrix;
	positionmatrix = glm::translate(positionmatrix, position);
	return positionmatrix;
}

void Entity::update(float dt)
{
	// for linking reasons
}