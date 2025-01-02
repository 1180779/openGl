#include "shader.hpp"

#include <iostream>

// loading shaders from files
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

GLuint compileShader(const char* source, GLenum shaderType);
GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint geometryShader = -1);

shader::shader(const char* vertexShaderC, const char* fragmentShaderC, const char* geometryShaderC)
{
    this->vertexShaderC = vertexShaderC;
    this->fragmentShaderC = fragmentShaderC;
    this->geometryShaderC = geometryShaderC;

    vertexShader = ::compileShader(vertexShaderC, GL_VERTEX_SHADER);
    fragmentShader = ::compileShader(fragmentShaderC, GL_FRAGMENT_SHADER);
    geometryShader = -1;
    if (geometryShaderC != nullptr)
        geometryShader = ::compileShader(geometryShaderC, GL_GEOMETRY_SHADER);

    program = ::linkProgram(vertexShader, fragmentShader, geometryShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if (geometryShader != -1) {
        glDeleteShader(geometryShader);
    }
}

shader::~shader()
{
    glDeleteProgram(program);
}

void shader::use()
{
    glUseProgram(program);
}

void shader::setb(const std::string& name, bool b) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)b);
}

void shader::seti(const std::string& name, int v) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), v);
}
void shader::set1f(const std::string& name, float v) const
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), v);
}

void shader::set4f(const std::string& name, float v0, float v1, float v2, float v3) const
{
    glUniform4f(glGetUniformLocation(program, name.c_str()), v0, v1, v2, v3);
}

// ------------------------------------------------
// implementation

GLuint compileShader(const char* source, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    return shader;
}

GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint geometryShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    if (geometryShader != -1)
        glAttachShader(program, geometryShader);
    glLinkProgram(program);

    // Check for linking errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Program Linking Failed:\n" << infoLog << std::endl;
    }

    return program;
}