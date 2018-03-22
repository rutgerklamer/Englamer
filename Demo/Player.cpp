#include "Demo/Player.h"

Player::Player() : Entity()
{
	Mesh* m = new Mesh();
	this->add_component(m);
	((Mesh*)this->get_component(MESH))->make_model("Assets/teapot.obj");
	Transform* t = new Transform();
	this->add_component(t);
	Collider* c = new Collider(((Mesh*)this->get_component(MESH))->get_min(), ((Mesh*)this->get_component(MESH))->get_max());
	this->add_component(c);
	Material* ma = new Material();
	ma->set_color(glm::vec3(0,0,1));
	ma->load_texture("Assets/brick.png");
	this->add_component(ma);
}

Player::~Player()
{
}

void Player::update(float dt)
{
	//((Transform*)this->get_component(TRANSFORM))->rotation.y += 0.04;
}

void Player::collision(Entity* other_entity)
{
	((Transform*)other_entity->get_component(TRANSFORM))->position.y += 0.01f;
}
