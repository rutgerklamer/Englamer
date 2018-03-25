#include "Englamer/Components/ParticleSystem.h"

ParticleSystem::ParticleSystem(glm::vec3 o, glm::vec3 c, glm::vec3 ec, glm::vec3 v, float l) : Component()
{
  this->set_component_type(PARTICLESYSTEM);
  origin = o;
  color = c;
  endcolor = ec;
  velocity = v;
  lifetime = l;
  spawner = false;
  randcolor = false;
  randvelocity = false;
}

void ParticleSystem::set_position(glm::vec3 o)
{
  origin = o;
}

void ParticleSystem::start()
{
  spawner = true;
}

void ParticleSystem::stop()
{
  spawner = false;
}

void ParticleSystem::set_random_color()
{
  randcolor = true;
}

void ParticleSystem::set_random_velocity()
{
  randvelocity= true;
}

ParticleSystem::~ParticleSystem()
{
  for (int i = 0; i < m_particles.size(); i++)
    delete m_particles[i];
}

void ParticleSystem::update(float dt)
{
  std::vector<Particle*>::iterator it = m_particles.begin();
    while (it != m_particles.end()) {
      if ((*it)->get_dead()) {
        delete *it;
        it = m_particles.erase(it);
      } else {
        it++;
      }
    }
  for (int i = 0; i < m_particles.size(); i++)
  {
    m_particles[i]->update(dt);
  }

  if (spawner)
    for (int i = 0; i < 10; i++)
    {
      Particle* p = new Particle( origin, (randcolor ? glm::vec3(rand()%1, rand() % 1, rand()% 1) : color), endcolor, (randvelocity ? glm::vec3(rand()%10 - 5, rand() % 10-5, rand()% 10-5): velocity), lifetime);
      m_particles.push_back(p);
    }
}
