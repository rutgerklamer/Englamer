#include "Demo/Player.h"

Player::Player() : Entity()
{
	Mesh* m = new Mesh();
	this->add_component(m);
	((Mesh*)this->get_component(MESH))->make_model("Assets/teapot.obj");
	Transform* t = new Transform();
	this->add_component(t);
}

Player::~Player()
{
}

void Player::update(float dt)
{

	
}