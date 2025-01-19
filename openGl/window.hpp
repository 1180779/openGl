
#ifndef U1180779_WINDOW_H
#define U1180779_WINDOW_H

#include "dataTypes.hpp"

struct window
{
    GLFWwindow* handle;
    const char* glslVersion;
    std::string name;
    int width = 1280;
    int height = 720;
    vec4 color;
};

#endif