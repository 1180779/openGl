
#ifndef _1180779_OBJECT_
#define _1180779_OBJECT_

#include "glad/glad.h"

class object 
{
public:
    virtual void render(GLint shaderProgram) const = 0;
};

#endif