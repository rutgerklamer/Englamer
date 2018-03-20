#ifndef FRUSTUM_H
#define FRUSTUM_H

#include <glm/glm.hpp>
#include <iostream>

#include "Englamer/Core/Config.h"
#include "Englamer/Entities/Entity.h"

struct Plane {
	glm::vec3 n;
	float D;
};

class Frustum
{
	public:
		Frustum();
		~Frustum();

		void calculate_frustum(glm::vec3 right, glm::vec3 up, glm::vec3 front, glm::vec3 pos, float fov, float near, float far);
		bool is_in_frustum(Entity* e);
	private:
		std::vector<Plane> planes;
};

#endif FRUSTUM_H
