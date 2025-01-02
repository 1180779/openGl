
#ifndef _1180779_TRIANGLE_
#define _1180779_TRIANGLE_

#include "glad/glad.h"

class triangle 
{
public:
    triangle();
    void render(GLint shaderProgram);

private:
    unsigned int VBO;
    unsigned int VAO;

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
};


#endif