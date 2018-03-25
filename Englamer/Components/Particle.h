#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Englamer/Components/Mesh.h"
#include "Englamer/Utils/Time.h"

class Particle {
  public:
    Particle(glm::vec3 o, glm::vec3 c, glm::vec3 ec, glm::vec3 v, float l);
    ~Particle();
    void update(float dt);
    bool get_dead();
    glm::vec3 get_color();
    glm::mat4 get_model_matrix();
    Mesh* get_mesh();
  private:
    glm::vec3 color;
    glm::vec3 startcolor;
    glm::vec3 endcolor;
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;
    glm::vec3 velocity;
    float lifetime;
    Mesh* mesh;
    Time time;
};

#endif PARTICLE_H
