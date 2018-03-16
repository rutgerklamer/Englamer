#ifndef INTERSECT_H
#define INTERSECT_H

#include <iostream>
#include <glm/gtx/rotate_vector.hpp>

#include "Englamer/Entities/Entity.h"

namespace Intersect
{
	bool intersectAABB(Entity* e1, Entity* e2);
};

#endif INTERSECT_H