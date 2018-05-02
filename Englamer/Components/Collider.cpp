#include "Englamer/Components/Collider.h"

Collider::Collider() : Component()
{
	set_component_type(COLLIDER);
}

Collider::~Collider()
{

}

void Collider::set_min_max(glm::vec3 mi, glm::vec3 ma)
{
	aabb_min = mi;
	aabb_max = ma;
	obb_min = mi;
	obb_max = ma;
}

glm::vec3 Collider::get_aabb_min()
{
	return aabb_min;
}

glm::vec3 Collider::get_aabb_max()
{
	return aabb_max;
}

glm::vec3 Collider::get_obb_min()
{
	return obb_min;
}

glm::vec3 Collider::get_obb_max()
{
	return obb_max;
}

void Collider::update_bb(glm::vec3 min, glm::vec3 max, glm::mat4 m)
{
	glm::mat4 absModel(glm::abs(m[0][0]), glm::abs(m[0][1]), glm::abs(m[0][2]), glm::abs(m[0][3]),
										 glm::abs(m[1][0]), glm::abs(m[1][1]), glm::abs(m[1][2]), glm::abs(m[1][3]),
										 glm::abs(m[2][0]), glm::abs(m[2][1]), glm::abs(m[2][2]), glm::abs(m[2][3]),
										 glm::abs(m[3][0]), glm::abs(m[3][1]), glm::abs(m[3][2]), glm::abs(m[3][3]));
	aabb_min = min;
	aabb_max = max;
  glm::vec3 center = (aabb_min + aabb_max) / 2.0f;
  glm::vec3 extent = (aabb_max - aabb_min) / 2.0f;

	glm::vec3 newCenter = glm::vec3(m * glm::vec4(center, 1.0f));
	glm::vec3 newExtent = glm::vec3(absModel * glm::vec4(extent, 0.0f));

	obb_min = newCenter - newExtent - glm::vec3(0.1f,0.1f,0.1f);
	obb_max = newCenter + newExtent + glm::vec3(0.1f,0.1f,0.1f);
}
