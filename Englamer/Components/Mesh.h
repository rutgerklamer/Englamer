#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Englamer/Core/Config.h"
#include "Englamer/Components/Component.h"

typedef struct {
	float x, y, z;
	float uvx, uvy;
	float nx, ny, nz;
} vertex;

typedef struct {
	std::vector<vertex> vertices;
	glm::vec3 min;
	glm::vec3 max;
} mesh_data;

class Mesh : public Component {
	public:
		Mesh();
		~Mesh();
		glm::vec3 get_color();
		void make_quad();
		void make_box();
		void make_model(const char* file);
		void draw();
		void bind();
		void calculate_bounding_box();
		int get_buffer_size();
		glm::vec3 get_min();
		glm::vec3 get_max();
		mesh_data m_mesh_data;
	private:
		glm::vec3 color;
		int size;
		GLuint VAO, VBO, EBO;
};

#endif MESH_H