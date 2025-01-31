
#include "camera.hpp"

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

    currentCamera->m_yaw += xoffset;
    currentCamera->m_pitch += yoffset;

    /* limit pitch */
    if(currentCamera->m_pitch > 89.0f)
        currentCamera->m_pitch = 89.0f;
    if (currentCamera->m_pitch < -89.0f)
        currentCamera->m_pitch = -89.0f;

    currentCamera->m_direction.x = cos(glm::radians(currentCamera->m_yaw)) * cos(glm::radians(currentCamera->m_pitch));
    currentCamera->m_direction.y = sin(glm::radians(currentCamera->m_pitch));
    currentCamera->m_direction.z = sin(glm::radians(currentCamera->m_yaw)) * cos(glm::radians(currentCamera->m_pitch));
    currentCamera->m_front = glm::normalize(currentCamera->m_direction);
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (!currentCamera)
        return;
    currentCamera->m_fov -= (float)yoffset;
    if (currentCamera->m_fov < currentCamera->m_fovMin)
        currentCamera->m_fov = currentCamera->m_fovMin;
    if (currentCamera->m_fov > currentCamera->m_fovMax)
        currentCamera->m_fov = currentCamera->m_fovMax;
}



void camera::disableCursor(const rendering& render)
{
    glfwSetInputMode(render.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void camera::setCallbacks(const rendering& render)
{
    glfwSetCursorPosCallback(render.window, mouseCallback);
    glfwSetScrollCallback(render.window, scrollCallback);
}

void camera::setCurrent()
{
    currentCamera = this;
}

camera& camera::processInput()
{
    float speed = m_cameraSpeed * m_render.deltaTime();
    if (glfwGetKey(m_render.window, GLFW_KEY_W) == GLFW_PRESS) {
        m_pos += speed * m_front;
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_S) == GLFW_PRESS) {
        m_pos -= speed * m_front;
    }

    if (glfwGetKey(m_render.window, GLFW_KEY_D) == GLFW_PRESS) {
        m_pos += speed * glm::normalize(glm::cross(m_front, m_up));
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_A) == GLFW_PRESS) {
        m_pos -= speed * glm::normalize(glm::cross(m_front, m_up));
    }

    if (glfwGetKey(m_render.window, GLFW_KEY_Z) == GLFW_PRESS) {
        m_pos += speed * m_up;
    }
    if (glfwGetKey(m_render.window, GLFW_KEY_X) == GLFW_PRESS) {
        m_pos -= speed * m_up;
    }
    return* this;
}

camera& camera::use(shader& sh, const std::string& nameView, const std::string& nameProj)
{
    sh.use();
    sh.set3f("viewPos", m_pos.x, m_pos.y, m_pos.z);
    sh.setMatrix4fv(nameProj, glm::perspective(glm::radians(m_fov), 800.0f / 600.0f, 0.1f, 100.0f));
    sh.setMatrix4fv(nameView, glm::lookAt(m_pos, m_pos + m_front, m_up));
    return *this;
}
