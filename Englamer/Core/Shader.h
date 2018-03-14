#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <iostream>

class Shader
{
public:
	GLuint shaderProgram;
	/**
	* Constructor
	* Takes in 5 paths in this order: Vertex Shader,
	Fragment Shader,
	Geometry Shader,
	Tessellation Control Shader,
	Tessellation Evaluation Shader,
	Geometry Shader
	*/
	Shader(const char* vertexPath = "Shaders/shader.vert", const char* fragmentPath = "Shaders/shader.frag");
	/**
	* Destructor
	*/
	~Shader();
	/**
	* Returns a string of a loaded shaderfile
	* Takes in a shaderpath
	*/
	std::string read_shader(const char* shaderPath);
	void compile_shader(GLuint& shader, GLuint type, std::string shadercode);
	GLuint vao;

	void Use();
};

#endif