#include <vector>
#include "Englamer/Scene/Skybox.h"


Skybox::Skybox(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front) : Mesh(), Material()
{
  //Make a cube
  make_model("Assets/cube.obj");
  load_cubemap(right, left, up, down, back, front);
  //Make a cubemap
}

Skybox::~Skybox()
{
}
