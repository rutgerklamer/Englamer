#include "Demo/Player.h"

Player::Player() : Entity()
{
	Mesh* m = new Mesh();
	this->add_component(m);
	((Mesh*)this->get_component(MESH))->make_model("Assets/dragon.obj");
	Transform* t = new Transform();
	t->rotation.y = rand()%45;
	this->add_component(t);
	Collider* c = new Collider();
	this->add_component(c);
	Material* ma = new Material();
	ma->set_color(glm::vec3(1,0.5,0.7));
	//ma->load_texture("Assets/brick.png");
	this->add_component(ma);
}

Player::~Player()
{
	delete this->get_component(MESH);
	delete this->get_component(MATERIAL);
	delete this->get_component(TRANSFORM);
	//delete this->get_component(COLLIDER);
	//delete this->get_component(LIGHT);
}

void Player::update(float dt)
{
}

void Player::collision(Entity* other_entity)
{

}
