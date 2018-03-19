#ifndef COLLIDER_H
#define COLLIDER_H

#include <glm/glm.hpp>

#include "Englamer/Entities/Component.h"

class Collider : public Component {
	public:
		Collider(glm::vec3 mi, glm::vec3 ma);
		~Collider();
		glm::vec3 get_min();
		glm::vec3 get_max();
	private:
		glm::vec3 min;
		glm::vec3 max;
};

#endif COLLIDER_H