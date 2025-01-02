
#ifndef _SHADERS_1180779_
#define _SHADERS_1180779_

#include <glad/glad.h>

#include <iostream>

class shaders {
public:

    shaders();
    shaders(const char* vertexShaderC, const char* fragmentShaderC, const char* geometryShaderC = nullptr);
    
    void createProgram();
    void deleteProgram();

    const char* vertexShaderC;
    const char* fragmentShaderC;
    const char* geometryShaderC;

    GLuint program;

private:
    void shadersInit();
    friend GLuint compileShader(const char* source, GLenum shaderType);
    friend GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint geometryShader);


    static constexpr GLuint invalidGLuint = -1;

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint geometryShader;
};

#endif