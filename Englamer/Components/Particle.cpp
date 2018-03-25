#include "Englamer/Components/Particle.h"

Particle::Particle(glm::vec3 o, glm::vec3 c, glm::vec3 ec, glm::vec3 v, float l)
{
  mesh = new Mesh();
  mesh->make_model("Assets/cube.obj");
  scale = glm::vec3(1,1,1);
  startcolor = c;
  endcolor = ec;
  position = o;
  velocity = v;
  lifetime = l;
  time.timer.start();
}

Particle::~Particle()
{

}

void Particle::update(float dt)
{
  position += velocity * dt;
  color = ((1.0f - (lifetime - time.timer.seconds() / lifetime)) * endcolor) + ((lifetime - time.timer.seconds() / lifetime) * startcolor);
}

bool Particle::get_dead()
{
  if (time.timer.seconds() > lifetime)
    return true;
  return false;
}


glm::vec3 Particle::get_color()
{
  return color;
}

glm::mat4 Particle::get_model_matrix()
{
  glm::mat4 modelmatrix;
	modelmatrix = glm::translate(modelmatrix, position);
  modelmatrix = glm::scale(modelmatrix, scale);
	return modelmatrix*glm::toMat4(glm::quat(rotation));
}

Mesh* Particle::get_mesh()
{
  return mesh;
}
