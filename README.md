Englamer
====

Englamer is a game making framework which uses openGL as a rendering system

Building
-----

On Debian-based Linux, install the following libraries:

	sudo apt-get install -y git cmake doxygen g++ libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxi-dev

On Windows and MacOS:
	Install make and cmake, and make sure you have atleast the C++11 compiler installed.
Use those command to build:

- mkdir build
- cd build
- cmake ..
- make

  Run
  -----
Then you can run the demo:

	./demo


  Documentation
  -----
   Make sure doxygen is installed
   the use these commands

      doxygen Doxyfile

Libraries
---------

- glfw: <http://www.glfw.org/>
- glew: <http://glew.sourceforge.net/>
- glm: <http://glm.g-truc.net/>
- chaiscript: <http://chaiscript.com/>

References
-----

- <http://learnopengl.com/>

Making multiple scenes
-----
To add more scenes, you can use this example:

```cpp
// Include all necessary files
#include <iostream>
#include "Englamer/Core/Core.h"
#include "Demo/Scene1.h"
#include "Demo/Scene2.h"

int main()
{
	// Make the new scenes
	Scene1* m_scene = new Scene1();
	Scene2* m_scene2 = new Scene2();
	// Create the core
	Core* m_core = new Core();
	// Make the core add the scenes to the scenemanager
	m_core->add_scene(m_scene);
	m_core->add_scene(m_scene2);
	// Initialize and run
	m_core->init();
	m_core->run();
	// Cleanup
	delete m_core;
	delete m_scene;
	delete m_scene2;
	return 0;
}
```

Adding entities to the scene
-----
Adding an entity to the scene is pretty simple as demonstrated below

```cpp
#include "Demo/Scene1.h"

Scene1::Scene1() : Superscene()
{
	// This should be an entity
	Player* p = new Player();
	// Set it's position
	((Transform*)p->get_component(TRANSFORM))->scale = glm::vec3 (5,5,5);
	// Add it to the scene
	this->add-child(p);
}

Scene1::~Scene1()
{
	// Always call this, otherwise all entities won't get deleted
	cleanup();
}

void Scene1::update(float dt)
{
	// This update get's calles every frame
	// You can update the entity here or in his own class
}
```


Adding/Getting/Changing Components of/to entities
-----
Adding components is easy
```cpp
#include "Demo/Player.h"

Player::Player() : Entity()
{
	// Create a Mesh
	Mesh* m = new Mesh();
	// Add the mesh to the component list
	this->add_component(m);
	// we can do this
	((Mesh*)this->get_component(MESH))->make_model("Assets/teapot.obj");
	// But we can also do this if we still got a reference to the object
	m->make_model("Assets/teapot.obj");
}

Player::~Player()
{
}

void Player::update(float dt)
{
	((Transform*)this->get_component(TRANSFORM))->position += glm::vec3(0.1f,-0.1f,0.1f);
	// We can acces the component in runtime
	if (we_are_dead)
		((Mesh*)this->get_component(MESH))->make_model("Assets/dead_teapot.obj");
}
```

License
-------

Copyright 2018 Rutger Klamer <rutger.klamer@gmail.com>

This project is provided as opensource. Do with it whatever you want.
