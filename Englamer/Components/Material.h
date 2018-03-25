#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include "Englamer/Components/Component.h"
#include "Englamer/Utils/Resourcemanager.h"

typedef struct {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
		glm::vec3 color;
    float shininess;
    float reflectivity;
		uint texture_id;
    uint cubemap_id;
} MMaterial;

class Material : public Component {
	public:
		Material();
		~Material();
		glm::vec3 get_color();
		void set_color(glm::vec3 c);
		uint get_texture();
		void load_texture(const char* file);
		glm::vec3 get_ambient();
		glm::vec3 get_diffuse();
		glm::vec3 get_specular();
		float get_shininess();
		void get_ambient(glm::vec3 a);
		void get_diffuse(glm::vec3 d);
		void get_specular(glm::vec3 s);
		void get_shininess(float s);
    uint get_cubemap();
    void load_cubemap(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front);
    void set_reflectivity(float r);
    float get_reflectivity();
	private:
		MMaterial m_material;
};
#endif MATERIAL_H
