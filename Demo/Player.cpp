#include "Demo/Player.h"

Player::Player() : Entity()
{
	this->mesh->make_model("Assets/teapot.obj");
}

Player::~Player()
{
}

void Player::update(float dt)
{

	
}