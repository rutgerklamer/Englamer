#include "Englamer/Entities/Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

glm::mat4 Entity::get_model_matrix()
{
		glm::mat4 modelmatrix;
		modelmatrix = glm::translate(modelmatrix, ((Transform*)this->get_component(TRANSFORM))->position);
		modelmatrix = glm::scale(modelmatrix, ((Transform*)this->get_component(TRANSFORM))->scale);
		return modelmatrix*glm::toMat4(glm::quat(((Transform*)this->get_component(TRANSFORM))->rotation));
}

void Entity::add_component(Component* component)
{
	if (component->get_component_type() == MESH)
		this->mesh = (Mesh*)component;
	if (component->get_component_type() == TRANSFORM)
		this->transform = (Transform*)component;
	if (component->get_component_type() == COLLIDER)
		this->collider = (Collider*)component;
}

Component* Entity::get_component(component_type c)
{
	if (c == MESH)
		return this->mesh;
	if (c == TRANSFORM)
		return this->transform;
	if (c == COLLIDER)
		return this->collider;
}

void Entity::update(float dt)
{
	// for linking reasons
}

void Entity::collision(Entity* other_entity)
{

}