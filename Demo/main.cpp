#include <iostream>
#include "Englamer/Core/Core.h"
#include "Demo/Scene1.h"

int main()
{
	Core* m_core = new Core();
	Scene1* m_scene = new Scene1();
	m_core->add_scene(m_scene);
	m_core->init();
	m_core->run();
	delete m_core;
	delete m_scene;
	return 0;
}
