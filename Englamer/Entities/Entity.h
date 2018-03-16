#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Englamer/Entities/Mesh.h"
#include "Englamer/Entities/Transform.h"
#include "Englamer/Entities/Collider.h"

class Entity
{
	public:
		Entity();
		~Entity();
		virtual void update(float dt);
		virtual void collision(Entity* other_entity);
		void add_component(Component* component);
		Component* get_component(component_type c);
		glm::mat4 get_model_matrix();
private:
		Mesh* mesh;
		Transform* transform;
		Collider* collider;
		int m_id;
};
#endif ENTITY_H