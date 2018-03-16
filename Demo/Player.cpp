#include "Demo/Player.h"

Player::Player() : Entity()
{
	Mesh* m = new Mesh();
	this->add_component(m);
	((Mesh*)this->get_component(MESH))->make_model("Assets/teapot.obj");
	Transform* t = new Transform();
	this->add_component(t);
	Collider* c = new Collider();
	this->add_component(c);
}

Player::~Player()
{
}

void Player::update(float dt)
{

}

void Player::collision(Entity* other_entity)
{
	((Transform*)other_entity->get_component(TRANSFORM))->position.y += 0.01f;
}