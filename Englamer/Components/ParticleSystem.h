#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <glm/glm.hpp>

#include "Englamer/Components/Component.h"
#include "Englamer/Components/Particle.h"

class ParticleSystem : public Component {
  public:
    ParticleSystem(glm::vec3 o, glm::vec3 c, glm::vec3 ec, glm::vec3 v, float l);
    ~ParticleSystem();
    void start();
    void stop();
    void set_random_velocity();
    void set_random_color();
    void set_position(glm::vec3 o);
    void update(float dt);
    std::vector<Particle*> m_particles;
  private:
    glm::vec3 origin;
    glm::vec3 color;
    glm::vec3 endcolor;
    glm::vec3 velocity;
    float lifetime;
    bool spawner;
    bool randcolor;
    bool randvelocity;
};

#endif PARTICLESYSTEM_H
