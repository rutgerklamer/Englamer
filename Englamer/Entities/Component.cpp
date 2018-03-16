#include "Englamer/Entities/Component.h"

Component::Component()
{
	this->m_component_type = UNDEFINED;
}

Component::~Component()
{

}

component_type Component::get_component_type()
{
	return this->m_component_type;
}

void Component::set_component_type(component_type c)
{
	this->m_component_type = c;
}

bool Component::get_enabled()
{
	return this->enabled;
}

void Component::set_enabled(bool b)
{
	this->enabled = b;
}