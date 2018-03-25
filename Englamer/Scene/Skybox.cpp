#include <vector>
#include "Englamer/Scene/Skybox.h"


Skybox::Skybox(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front) : Mesh(), Material()
{
  //Make a cube
  make_model("Assets/cube.obj");
  load_cubemap(right, left, up, down, back, front);
  //Make a cubemap
  m_skybox_shader = new Shader("Data/Shaders/skybox_shader.vs", "Data/Shaders/skybox_shader.fs");
  m_skybox_shader->Use();
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, this->get_cubemap());
  glUniform1i(glGetUniformLocation(m_skybox_shader->shaderProgram, "skybox"), 0);

}

Skybox::~Skybox()
{

}

Shader* Skybox::get_shader()
{
  return this->m_skybox_shader;
}
