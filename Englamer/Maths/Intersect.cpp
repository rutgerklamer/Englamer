#include "Englamer/Maths/Intersect.h"

bool Intersect::intersectAABB(Entity* e1, Entity* e2)
{
	glm::vec3 e1min = ((Transform*)e1->get_component(TRANSFORM))->position + (((Collider*)e1->get_component(COLLIDER))->get_min() * ((Transform*)e1->get_component(TRANSFORM))->scale);
	glm::vec3 e2min = ((Transform*)e2->get_component(TRANSFORM))->position + (((Collider*)e2->get_component(COLLIDER))->get_min() * ((Transform*)e2->get_component(TRANSFORM))->scale);
	glm::vec3 e1max = ((Transform*)e1->get_component(TRANSFORM))->position + (((Collider*)e1->get_component(COLLIDER))->get_max() * ((Transform*)e1->get_component(TRANSFORM))->scale);
	glm::vec3 e2max = ((Transform*)e2->get_component(TRANSFORM))->position + (((Collider*)e2->get_component(COLLIDER))->get_max() * ((Transform*)e2->get_component(TRANSFORM))->scale);

	if (((Transform*)e1->get_component(TRANSFORM))->position.x < ((Transform*)e2->get_component(TRANSFORM))->position.x) {
		if (glm::vec4(e1max, 1).x < (glm::vec4(e2min, 1).x)) {
			return false;
		}
	}
	else if (glm::vec4(e1min, 1).x >  glm::vec4(e2max, 1).x) {
		return false;
	}
	if (((Transform*)e1->get_component(TRANSFORM))->position.y < ((Transform*)e2->get_component(TRANSFORM))->position.y) {
		if (glm::vec4(e1max, 1).y < glm::vec4(e2min, 1).y) {
			return false;
		}
	}
	else if (glm::vec4(e1min, 1).y > glm::vec4(e2max, 1).y) {
		return false;
	}
	if (((Transform*)e1->get_component(TRANSFORM))->position.z < ((Transform*)e2->get_component(TRANSFORM))->position.z) {
		if (glm::vec4(e1max, 1).z < glm::vec4(e2min, 1).z) {
			return false;
		}
	}
	else if (glm::vec4(e1min, 1).z >  glm::vec4(e2max, 1).z) 
		return false;
	return true;
}