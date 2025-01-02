
#ifndef _1180779_RENDERING_
#define _1180779_RENDERING_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imGui/imgui.h"
#include <string>


class rendering 
{
public:
    rendering(std::string windowName = "openGL");
    ~rendering();
    void clearColor();
    void swapBuffers();
    void initGL();

    GLFWwindow* window;
    const char* glsl_version;
    ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 1.00f);
};

#endif