
#ifndef U1180779_CAMERA_H
#define U1180779_CAMERA_H

#include "shader.hpp"
#include "rendering.hpp"
#include <glm/glm.hpp>

class camera 
{
public:
    /* sets window input mode to cursor disabled */
    static void disableCursor(const rendering& render);
    
    /* sets cursor callback */
    static void setCursorCallback(const rendering& render);

    /* set mouse movement to modify this cameras yaw and pitch */
    void setCurrent();
    camera(const rendering& render, float speed = 2.f, float pitchMax = 89.f, float pitchMin = -89.f)
        : m_render(render), m_cameraSpeed(speed), m_pitchMax(pitchMax), m_pitchMin(pitchMin) { }

    /* process input */
    camera& processInput();

    /* set 4f matrix with name in the shader */
    camera& use(shader& sh, const std::string& name = "view");

private:
    const rendering& m_render;
    glm::vec3 m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_cameraUp = glm::vec3(0.f, 1.f, 0.f);
    glm::vec3 m_direction = glm::vec3(1.0f, 1.0f, 1.0f);

    friend void mouseCallback(GLFWwindow* window, double xpos, double ypos);

    float m_cameraSpeed;
    float m_yaw = -90.f;
    float m_pitch = 0.f;

    float m_pitchMax;
    float m_pitchMin;
};

static camera* currentCamera = nullptr;
static float lastX = 400, lastY = 300;
static void mouseCallback(GLFWwindow* window, double xpos, double ypos);

#endif