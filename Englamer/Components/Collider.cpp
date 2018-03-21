#include "Englamer/Components/Collider.h"

Collider::Collider(glm::vec3 mi, glm::vec3 ma) : Component()
{
	set_component_type(COLLIDER);
	min = mi;
	max = ma;
}

Collider::~Collider()
{

}

glm::vec3 Collider::get_min()
{
	return min;
}

glm::vec3 Collider::get_max()
{
	return max;
}
