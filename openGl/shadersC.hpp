
#ifndef _1180779_SHADERSC_
#define _1180779_SHADERSC_

const char* vertexSS = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
};
)";

const char* fragmentSS = R"(
#version 330 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
} 
)";

// --------------------------------------------------

const char* fragmentSS2 = R"(
#version 330 core
out vec4 FragColor;
uniform vec4 ourColor; // we set this variable in the OpenGL code.
void main()
{
    FragColor = ourColor;
}   
)";


#endif