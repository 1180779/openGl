
#include "cameraView.hpp"
#include "sceneView.hpp"
#include "application.hpp"
#include "camera.hpp"

void cameraView::handleInput()
{
    m_parent.scene.cameraMan.getCamera().processInput(
        m_parent.app.window.handle, m_parent.app.deltaTime());
    if (glfwGetKey(m_parent.app.window.handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        m_parent.changeSubView(sceneView::subView::ui);
        return;
    }
    if(glfwGetKey(m_parent.app.window.handle, GLFW_KEY_N) == GLFW_PRESS && !m_nDown) 
    {
        m_nDown = true;
        m_parent.scene.cameraMan.nextCamera();
    }
    else if(glfwGetKey(m_parent.app.window.handle, GLFW_KEY_N) == GLFW_RELEASE) 
    {
        m_nDown = false;
    }
}

void cameraView::onEnter()
{
    m_parent.scene.cameraMan.getCamera().setCurrent();
    glfwSetInputMode(m_parent.app.window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(m_parent.app.window.handle, mouseCallback);
    glfwSetScrollCallback(m_parent.app.window.handle, scrollCallback);
}

void cameraView::update(float dt)
{

}

void cameraView::ui()
{

}

void cameraView::render() const
{

}

void cameraView::onExit()
{
    glfwSetInputMode(m_parent.app.window.handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPosCallback(m_parent.app.window.handle, NULL);
    glfwSetScrollCallback(m_parent.app.window.handle, NULL);
}
