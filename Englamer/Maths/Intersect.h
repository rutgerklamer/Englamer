#ifndef INTERSECT_H
#define INTERSECT_H

#include <iostream>
#include <glm/gtx/rotate_vector.hpp>

namespace Intersect
{
	 bool intersectAABB(glm::vec3 min1, glm::vec3 min2, glm::vec3 max1, glm::vec3 max2, glm::vec3 pos1, glm::vec3 pos2);
};

#endif INTERSECT_H