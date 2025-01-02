
#ifndef _1180779_TRIANGLE_
#define _1180779_TRIANGLE_

#include "object.hpp"

class triangle : public object
{
public:
    triangle();
    virtual void render(GLint shaderProgram) const;

private:
    GLuint VBO;
    GLuint VAO;

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
};


#endif