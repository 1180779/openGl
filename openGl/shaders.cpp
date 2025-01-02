#include "shaders.hpp"

#include <iostream>

// loading shaders from files
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

GLuint compileShader(const char* source, GLenum shaderType);
GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint geometryShader = -1);

shaders::shaders()
{
    vertexShaderC = nullptr;
    fragmentShaderC = nullptr;
    geometryShaderC = nullptr;

    shadersInit();
}

shaders::shaders(const char* vertexShaderC, const char* fragmentShaderC, const char* geometryShaderC)
{
    this->vertexShaderC = vertexShaderC;
    this->fragmentShaderC = fragmentShaderC;
    this->geometryShaderC = geometryShaderC;

    shadersInit();
}

void shaders::shadersInit()
{
    vertexShader = invalidGLuint;
    fragmentShader = invalidGLuint;
    geometryShader = invalidGLuint;

    program = invalidGLuint;
}

void shaders::createProgram()
{
    if (program != invalidGLuint) {
        glDeleteProgram(program);
    }
    vertexShader = ::compileShader(vertexShaderC, GL_VERTEX_SHADER);
    fragmentShader = ::compileShader(fragmentShaderC, GL_FRAGMENT_SHADER);
    if(geometryShaderC != nullptr)
        geometryShader = ::compileShader(geometryShaderC, GL_GEOMETRY_SHADER);

    program = ::linkProgram(vertexShader, fragmentShader, geometryShader);

    glDeleteShader(vertexShader);
    vertexShader = invalidGLuint;
    glDeleteShader(fragmentShader);
    fragmentShader = invalidGLuint;
    if (geometryShader != shaders::invalidGLuint) {
        glDeleteShader(geometryShader);
        geometryShader = invalidGLuint;
    }
}

void shaders::deleteProgram()
{
    if (program == invalidGLuint)
        return;
    glDeleteProgram(program);
    program = invalidGLuint;
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
    if (geometryShader != shaders::invalidGLuint)
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