
#include "deltaTime.hpp"

void deltaTime::measure()
{
    currFrame = glfwGetTime();
    dt = currFrame - lastFrame;
    lastFrame = currFrame;
}
