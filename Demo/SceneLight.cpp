#include "Demo/SceneLight.h"

SceneLight::SceneLight() : Entity()
{
	Transform* t = new Transform();
	this->add_component(t);
	Light* l = new Light();
	l->set_light_color(glm::vec3(1.0f, 0.3f, 0.0f));
	l->set_intensity(0.5f);
	this->add_component(l);

	ParticleSystem* ps = new ParticleSystem(glm::vec3(0,0,0), glm::vec3(1,0.3,0), glm::vec3(0.1,0.05,0), glm::vec3(0,10,0), 1.0f);
	ps->start();
	ps->set_random_velocity();
	this->add_component(ps);
}

SceneLight::~SceneLight()
{
	//delete this->get_component(MESH);
	//delete this->get_component(MATERIAL);
	delete this->get_component(TRANSFORM);
	//delete this->get_component(COLLIDER);
	delete this->get_component(LIGHT);

}

void SceneLight::update(float dt)
{
	((Transform*)this->get_component(TRANSFORM))->position.y = cos(-glfwGetTime()) * 30.0f + 20.0f;
	((Transform*)this->get_component(TRANSFORM))->position.x = sin(-glfwGetTime() * 5.0f) * 20.0f;
	((Transform*)this->get_component(TRANSFORM))->position.z = cos(glfwGetTime() * 5.0f) * 20.0f;
	((ParticleSystem*)this->get_component(PARTICLESYSTEM))->set_position(((Transform*)this->get_component(TRANSFORM))->position);
}

void SceneLight::collision(Entity* other_entity)
{

}
