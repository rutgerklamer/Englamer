#include "Englamer/Core/Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	//Get all the shader codes
	std::string VertexShaderCode = read_shader(vertexPath);
	std::string FragmentShaderCode = read_shader(fragmentPath);

	//Make the shaders
	GLuint vertex, fragment;
	compile_shader(vertex, GL_VERTEX_SHADER, VertexShaderCode);
	compile_shader(fragment, GL_FRAGMENT_SHADER, FragmentShaderCode);

	//Create shader program
	this->shaderProgram = glCreateProgram();
	//Attach fragment and vertex shader
	if (VertexShaderCode != "") glAttachShader(this->shaderProgram, vertex);
	if (FragmentShaderCode != "") glAttachShader(this->shaderProgram, fragment);
	glLinkProgram(this->shaderProgram);

	//See if linking was correct
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
		std::cout << "Error linking shaderprogram: " << infoLog << std::endl;
	}
	//Delete shaders since they are already bind to the program
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

Shader::~Shader()
{

}

void Shader::compile_shader(GLuint& shader, GLuint type, std::string shadercode)
{
	GLint success;
	GLchar infoLog[512];
	shader = glCreateShader(type);
	char const* VertexSourcePointer = shadercode.c_str();
	//Compile vertex shader
	glShaderSource(shader, 1, &VertexSourcePointer, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Error compiling vertex shader: " << infoLog << std::endl;
	}
}

std::string Shader::read_shader(const char* shaderPath)
{
	std::string shaderCode;
	std::ifstream shaderStream(shaderPath);
	std::string line;
	while (getline(shaderStream, line))
		shaderCode += "\n" + line;
	shaderStream.close();
	return shaderCode;
}

void Shader::Use()
{
	glUseProgram(shaderProgram);
}