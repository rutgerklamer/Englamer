#include "Englamer/Maths/Intersect.h"

bool Intersect::intersectAABB(glm::vec3 min1, glm::vec3 min2, glm::vec3 max1, glm::vec3 max2, glm::vec3 pos1, glm::vec3 pos2)
{
	int intersectionCount = 0;
	if (pos1.x < pos2.x) {
		if (glm::vec4(max1, 1).x >(glm::vec4(min2, 1).x)) {
			intersectionCount++;
		}
	}
	else if (glm::vec4(min1, 1).x <  glm::vec4(max2, 1).x) {
		intersectionCount++;
	}

	if (pos1.y < pos2.y) {
		if (glm::vec4(max1, 1).y > glm::vec4(min2, 1).y) {
			intersectionCount++;
		}
	}
	else if (glm::vec4(min1, 1).y < glm::vec4(max2, 1).y) {
		intersectionCount++;
	}
	if (pos1.z < pos2.z) {
		if (glm::vec4(max1, 1).z > glm::vec4(min2, 1).z) {
			intersectionCount++;
		}
	}
	else if (glm::vec4(min1, 1).z <  glm::vec4(max2, 1).z) {
		intersectionCount++;
	}
	if (intersectionCount > 2) {
		return true;
	}
	else {
		return false;
	}
}