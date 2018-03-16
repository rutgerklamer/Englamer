#include "Englamer/Entities/Entity.h"

Entity::Entity()
{
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

void Entity::add_component(Component* component)
{
	if (component->get_component_type() == MESH)
		this->mesh = (Mesh*)component;
	if (component->get_component_type() == TRANSFORM)
		this->transform = (Transform*)component;
}

Component* Entity::get_component(component_type c)
{
	if (c == MESH)
		return this->mesh;
	if (c == TRANSFORM)
		return this->transform;
}

void Entity::update(float dt)
{
	// for linking reasons
}
