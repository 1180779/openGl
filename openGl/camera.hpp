
#ifndef U1180779_CAMERA_H
#define U1180779_CAMERA_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "shader.hpp"
#include <glm/glm.hpp>

class camera 
{
public:

    /* set mouse movement to modify this cameras yaw and pitch */
    void setCurrent();
    camera(float speed = 2.f, float yaw = -90.f,
        float pitchMax = 89.f, float pitchMin = -89.f, 
        float fovMin = 1.0f, float fovMax = 45.0f)
        : m_cameraSpeed(speed), m_yaw(yaw),
        m_pitchMax(pitchMax), m_pitchMin(pitchMin), 
        m_fovMax(fovMax), m_fovMin(fovMin) 
    {
        m_fov = m_fovMax;
    }

    inline glm::vec3 getPos() const { return m_pos; }

    /* process input */
    void processInput(GLFWwindow* window, float dt);

    /* set 4f matrix with name in the shader */
    void use(const shader& sh, 
        const std::string& nameView = "view", 
        const std::string& nameProj = "projection") const;

private:
    glm::vec3 m_pos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_up = glm::vec3(0.f, 1.f, 0.f);
    glm::vec3 m_direction = glm::vec3(1.0f, 1.0f, 1.0f);

    friend void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    friend void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    float m_cameraSpeed;
    float m_yaw;

    float m_pitch = 0.f;
    float m_pitchMax;
    float m_pitchMin;

    float m_fov;
    float m_fovMax;
    float m_fovMin;
};

extern camera* currentCamera;
extern float lastX, lastY;
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);


#endif