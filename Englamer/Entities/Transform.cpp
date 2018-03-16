#include "Englamer/Entities/Transform.h"

Transform::Transform() : Component()
{
	set_component_type(TRANSFORM);
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
	position = glm::vec3(0, 0, 0);
}

Transform::~Transform()
{

}