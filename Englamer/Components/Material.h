#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include "Englamer/Components/Component.h"
#include "Englamer/Utils/Resourcemanager.h"

class Material : public Component {
	public:
		Material();
		~Material();
		glm::vec3 get_color();
		void set_color(glm::vec3 c);
		uint get_texture();
		void load_texture(const char* file);
	private:
		glm::vec3 color;
		uint texture_id;
};
#endif MATERIAL_H
