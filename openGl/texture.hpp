
#ifndef _1180779_TEXTURE_H_
#define _1180779_TEXTURE_H_

#include <string>
#include "glad/glad.h"
#include "stb_image.h"

class texture 
{
public:
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    int getNrChanngels() { return m_nrChannels; }

    void use(int i = 0);

    texture(std::string source, GLenum format = GL_RGB);

private:
    int m_width;
    int m_height;
    int m_nrChannels;
    unsigned char* m_data;
    GLuint m_texture;
};

#endif