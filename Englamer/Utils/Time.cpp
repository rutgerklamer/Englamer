#include "Time.h"

Time::Time()
{

}

Time::~Time()
{

}

void Time::update()
{
  current_time = glfwGetTime();
  dt = current_time - previous_time;
  previous_time = glfwGetTime();
  fps++;
  if (current_time - last_time >= 1.0) {
      std::cout << "deltaTime ( " << get_deltatime() << " ) fps ( " << fps << " )" << std::endl;
      fps = 0;
      last_time = glfwGetTime();
  }
}

int Time::get_fps()
{
  return this->fps;
}

float Time::get_deltatime()
{
  return this->dt;
}
