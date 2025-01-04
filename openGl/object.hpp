
#ifndef U1180779_OBJECT_H
#define U1180779_OBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class object 
{
public:
    virtual void render() const = 0;
    virtual glm::mat4 model() { return glm::mat4(1.0f); }
};

#endif