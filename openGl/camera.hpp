
#ifndef U1180779_CAMERA_H
#define U1180779_CAMERA_H

#include "shader.hpp"
#include "rendering.hpp"
#include <glm/glm.hpp>

class camera 
{
public:
    camera(const rendering& render, const float speed = 2.f) : m_render(render), m_cameraSpeed(speed) { }
    camera& processInput();
    const camera& use(shader& sh, const std::string& name = "view") const;

private:
    const rendering& m_render;
    glm::vec3 m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_cameraUp = glm::vec3(0.f, 1.f, 0.f);

    float m_cameraSpeed;
};

#endif