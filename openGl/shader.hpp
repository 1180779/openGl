
#ifndef U1180779_SHADER_H
#define U1180779_SHADER_H

#include <glad/glad.h>

#include <iostream>

class shader 
{
public:

    shader(const char* vertexShaderC, const char* fragmentShaderC, const char* geometryShaderC = nullptr);
    ~shader();

    void use();

    void setb(const std::string& name, bool v) const;
    void set1i(const std::string& name, int v) const;
    void set1f(const std::string& name, float v) const;
    void set4f(const std::string& name, float v0, float v1, float v2, float v3) const;

    const char* vertexShaderC;
    const char* fragmentShaderC;
    const char* geometryShaderC;

private:
    GLuint m_program;

    GLuint m_vertexShader;
    GLuint m_fragmentShader;
    GLuint m_geometryShader;
};

#endif