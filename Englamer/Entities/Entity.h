#ifndef ENTITY_H
#define ENTITY_H

#include "Englamer/Components/Mesh.h"
#include "Englamer/Components/Transform.h"
#include "Englamer/Components/Collider.h"
#include "Englamer/Components/Light.h"

class Entity
{
	public:
		Entity();
		~Entity();
		virtual void update(float dt);
		virtual void collision(Entity* other_entity);
		void add_component(Component* component);
		Component* get_component(component_type c);
private:
		Mesh* mesh;
		Transform* transform;
		Collider* collider;
		Light* light;
};
#endif ENTITY_H