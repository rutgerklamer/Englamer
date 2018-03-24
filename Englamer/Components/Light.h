#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include "Englamer/Components/Component.h"

typedef struct {
	glm::vec3 position;
	glm::vec3 light_color;
	float specular_strength;
	float intensity;
} light_data;

class Light : public Component
{
	public:
		Light();
		~Light();
		glm::vec3 get_light_color();
		glm::vec3 get_position();
		float get_specular_light_strength();
		float get_intensity();

		void set_light_color(glm::vec3 c);
		void set_position(glm::vec3 p);
		void set_specular_light_strength(float s);
		void set_intensity(float i);
	private:
		light_data m_light_data;
};

#endif LIGHT_H
