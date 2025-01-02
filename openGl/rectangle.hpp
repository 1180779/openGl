
#ifndef _1180779_RECTANGLE_
#define _1180779_RECTANGLE_

#include "object.hpp"

class rectangle : public object
{
public:
    rectangle();
    virtual void render(GLint shaderProgram) const;

private:
    GLuint VBO;
    GLuint EBO;
    GLuint VAO;

    float vertices[12] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[6] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };
};

#endif