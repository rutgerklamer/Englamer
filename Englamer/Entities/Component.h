#ifndef COMPONENT_H
#define COMPONENT_H

enum component_type {
	UNDEFINED, MESH, TRANSFORM
};

class Component
{
	public:
		Component();
		~Component();
		component_type get_component_type();
		void set_component_type(component_type c);
		bool get_enabled();
		void set_enabled(bool b);
	private:
		component_type m_component_type;
		bool enabled;
};
#endif COMPONENT_H