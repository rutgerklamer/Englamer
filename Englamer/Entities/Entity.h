#ifndef ENTITY_H
#define ENTITY_H

#include "Englamer/Components/Mesh.h"
#include "Englamer/Components/Transform.h"
#include "Englamer/Components/Collider.h"
#include "Englamer/Components/Light.h"
#include "Englamer/Components/Material.h"
#include "Englamer/Components/ParticleSystem.h"

class Entity
{
	public:
		Entity();
		~Entity();
		virtual void update(float dt);
		void engine_update(float dt);
		virtual void collision(Entity* other_entity);
		void add_component(Component* component);
		Component* get_component(component_type c);
private:
		Mesh* mesh;
		Transform* transform;
		Collider* collider;
		Light* light;
		Material* material;
		ParticleSystem* particle_system;
};
#endif ENTITY_H
