#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Englamer/Entities/Component.h"

class Transform : public Component {
	public:
		Transform();
		~Transform();
		glm::mat4 get_model_matrix();
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;
};
#endif TRANSFORM_H