
#include "camera.hpp"

camera& camera::processInput()
{
    float speed = m_cameraSpeed * m_render.deltaTime();
    if (glfwGetKey(m_render.window, GLFW_KEY_W) == GLFW_PRESS) {
        m_cameraPos += speed * m_cameraFront;
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_S) == GLFW_PRESS) {
        m_cameraPos -= speed * m_cameraFront;
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_A) == GLFW_PRESS) {
        m_cameraPos -= speed * glm::normalize(glm::cross(m_cameraFront, m_cameraUp));
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_D) == GLFW_PRESS) {
        m_cameraPos += speed * glm::normalize(glm::cross(m_cameraFront, m_cameraUp));
    }
    return* this;
}

const camera& camera::use(shader& sh, const std::string& name) const
{
    sh.setMatrix4fv(name, glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp));
    return *this;
}
