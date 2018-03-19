#include "Englamer/Entities/Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::add_component(Component* component)
{
	if (component->get_component_type() == MESH)
		this->mesh = (Mesh*)component;
	if (component->get_component_type() == TRANSFORM)
		this->transform = (Transform*)component;
	if (component->get_component_type() == COLLIDER)
		this->collider = (Collider*)component;
	if (component->get_component_type() == LIGHT)
		this->light = (Light*)component;
}

Component* Entity::get_component(component_type c)
{
	if (c == MESH)
		return this->mesh;
	else if (c == TRANSFORM)
		return this->transform;
	else if (c == COLLIDER)
		return this->collider;
	else if (c == LIGHT)
		return this->light;
}

void Entity::update(float dt)
{
	// for linking reasons
}

void Entity::collision(Entity* other_entity)
{

}