#include "Englamer/Entities/Entity.h"

Entity::Entity()
{
	mesh = NULL;
	transform = NULL;
	collider = NULL;
	light = NULL;
	material = NULL;
	particle_system = NULL;
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
	if (component->get_component_type() == COLLIDER) {
		this->collider = (Collider*)component;
		if (mesh != NULL)
			this->collider->set_min_max(mesh->get_min(), mesh->get_max());
	} if (component->get_component_type() == LIGHT)
		this->light = (Light*)component;
	if (component->get_component_type() == MATERIAL)
		this->material = (Material*)component;
	if (component->get_component_type() == PARTICLESYSTEM)
		this->particle_system = (ParticleSystem*)component;
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
	else if (c == MATERIAL)
		return this->material;
	else if (c == PARTICLESYSTEM)
		return this->particle_system;
}

void Entity::update(float dt)
{
	// for linking reasons
}

void Entity::engine_update(float dt)
{
	if (collider != NULL && transform != NULL)
		collider->update_bb(mesh->get_min(), mesh->get_max(), transform->get_rotation_matrix()*transform->get_scale_matrix());
	if (particle_system != NULL)
		particle_system->update(dt);
}

void Entity::collision(Entity* other_entity)
{

}
