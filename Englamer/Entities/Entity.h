#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Englamer/Entities/Mesh.h"

class Entity
{
	public:
		Entity();
		~Entity();
		virtual void update(float dt);
		void add_component(Component* component);
		Component* get_component(component_type c);
		glm::mat4 get_model_matrix();
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
private:
		Mesh* mesh;
};
#endif ENTITY_H