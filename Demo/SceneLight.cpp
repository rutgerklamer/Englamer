#include "Demo/SceneLight.h"

SceneLight::SceneLight() : Entity()
{
	Transform* t = new Transform();
	this->add_component(t);
	Light* l = new Light();
	l->set_light_color(glm::vec3(1.0f, 0.8f, 0.3f));
	l->set_intensity(0.5f);
	this->add_component(l);
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
	((Transform*)this->get_component(TRANSFORM))->position.y = cos(-glfwGetTime()) * 5.0f + 10.0f;
}

void SceneLight::collision(Entity* other_entity)
{

}
