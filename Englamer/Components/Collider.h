#ifndef COLLIDER_H
#define COLLIDER_H

#include <glm/glm.hpp>

#include "Englamer/Components/Component.h"

class Collider : public Component {
	public:
		Collider();
		~Collider();
		void set_min_max(glm::vec3 mi, glm::vec3 ma);
		glm::vec3 get_aabb_min();
		glm::vec3 get_aabb_max();
		glm::vec3 get_obb_min();
		glm::vec3 get_obb_max();
		void update_bb(glm::vec3 min, glm::vec3 max,glm::mat4 m);
	private:
		glm::vec3 aabb_min;
		glm::vec3 aabb_max;
		glm::vec3 obb_min;
		glm::vec3 obb_max;
};

#endif COLLIDER_H
