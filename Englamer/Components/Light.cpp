#include "Englamer/Components/Light.h"

Light::Light() : Component()
{
	set_component_type(LIGHT);
	m_light_data.position = glm::vec3(0, 0, 0);
	m_light_data.light_color = glm::vec3(1,1,1);
	m_light_data.specular_strength = 1.0f;
}

Light::~Light()
{

}

glm::vec3 Light::get_light_color()
{
	return m_light_data.light_color;
}

glm::vec3 Light::get_position()
{
	return m_light_data.position;

}

float Light::get_specular_light_strength()
{
	return m_light_data.specular_strength;

}

void Light::set_light_color(glm::vec3 c)
{
	m_light_data.light_color = c;
}

void Light::set_position(glm::vec3 p)
{
	m_light_data.position = p;
}

void Light::set_specular_light_strength(float s)
{
	m_light_data.specular_strength = s;
}
