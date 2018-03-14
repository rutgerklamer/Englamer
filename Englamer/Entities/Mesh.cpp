#include "Englamer/Entities/Mesh.h"
#include "Englamer/Utils/Objloader.h"
#include "Englamer/Utils/Resourcemanager.h"

Mesh::Mesh()
{
	color = glm::vec3(1,1,1);
}

Mesh::~Mesh()
{

}

glm::vec3 Mesh::get_color()
{
	return this->color;
}

int Mesh::get_buffer_size()
{
	return this->size;
}


void Mesh::make_quad()
{
	m_mesh_data.vertices = {
		vertex{ -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,0.0f, 0.0f, 0.0f },
		vertex{ 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }
	};
	this->size = m_mesh_data.vertices.size();
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
}

void Mesh::make_box()
{
	m_mesh_data.vertices = {
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		vertex{ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
	};
	calculate_bounding_box();
	this->size = m_mesh_data.vertices.size();
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
}

void Mesh::make_model(const char* file)
{
	if (Resourcemanager::does_object_exist(file)) {
		m_mesh_data.vertices = objloader::load_object(file);
		Resourcemanager::create_object_existance(file, &m_mesh_data.vertices);
	}
	else {
		m_mesh_data.vertices = Resourcemanager::get_object_existance(file);
		m_mesh_data.vertices = objloader::load_object(file);
	}
	calculate_bounding_box();
	this->size = m_mesh_data.vertices.size();
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
}

void Mesh::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_mesh_data.vertices.size() * sizeof(vertex), &m_mesh_data.vertices[0], GL_STATIC_DRAW);
}

void Mesh::draw()
{
	glBindVertexArray(this->VAO);
}

void Mesh::calculate_bounding_box()
{
	for (int i = 0; i < m_mesh_data.vertices.size(); i++) {
		if (m_mesh_data.vertices[i].x > m_mesh_data.max.x)
			m_mesh_data.max.x = m_mesh_data.vertices[i].x;
		else if (m_mesh_data.vertices[i].y > m_mesh_data.max.y)
			m_mesh_data.max.y = m_mesh_data.vertices[i].y;
		else if (m_mesh_data.vertices[i].z > m_mesh_data.max.z)
			m_mesh_data.max.z = m_mesh_data.vertices[i].z;

		if (m_mesh_data.vertices[i].x < m_mesh_data.min.x)
			m_mesh_data.min.x = m_mesh_data.vertices[i].x;
		else if (m_mesh_data.vertices[i].y < m_mesh_data.min.y)
			m_mesh_data.min.y = m_mesh_data.vertices[i].y;
		else if (m_mesh_data.vertices[i].z < m_mesh_data.min.z)
			m_mesh_data.min.z = m_mesh_data.vertices[i].z;
	}
}