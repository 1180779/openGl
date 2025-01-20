
#include "camera.hpp"

camera* currentCamera = nullptr;
float lastX = 400, lastY = 300;

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
    lastX = xpos;
    lastY = ypos;

    if (!currentCamera)
        return;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    currentCamera->yaw += xoffset;
    currentCamera->pitch += yoffset;

    /* limit pitch */
    if(currentCamera->pitch > 89.0f)
        currentCamera->pitch = 89.0f;
    if (currentCamera->pitch < -89.0f)
        currentCamera->pitch = -89.0f;

    currentCamera->m_direction.x = cos(glm::radians(currentCamera->yaw)) * cos(glm::radians(currentCamera->pitch));
    currentCamera->m_direction.y = sin(glm::radians(currentCamera->pitch));
    currentCamera->m_direction.z = sin(glm::radians(currentCamera->yaw)) * cos(glm::radians(currentCamera->pitch));
    currentCamera->m_front = glm::normalize(currentCamera->m_direction);
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (!currentCamera)
        return;
    currentCamera->fov -= (float)yoffset;
    if (currentCamera->fov < currentCamera->fovMin)
        currentCamera->fov = currentCamera->fovMin;
    if (currentCamera->fov > currentCamera->fovMax)
        currentCamera->fov = currentCamera->fovMax;
}

void camera::setCurrent()
{
    currentCamera = this;
}

void camera::processInput(GLFWwindow* window, float dt)
{
    float speed = this->speed * dt;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        pos += speed * m_front;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        pos -= speed * m_front;
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        pos += speed * glm::normalize(glm::cross(m_front, m_up));
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        pos -= speed * glm::normalize(glm::cross(m_front, m_up));
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        pos += speed * m_up;
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        pos -= speed * m_up;
    }
}

void camera::use(
    const shader& sh, 
    const std::string& nameView, 
    const std::string& nameProj) const
{
    sh.use();
    sh.set3f("viewPos", pos.x, pos.y, pos.z);
    sh.setMatrix4fv(nameProj, glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f));
    sh.setMatrix4fv(nameView, glm::lookAt(pos, pos + m_front, m_up));
}
