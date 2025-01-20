
#include "sceneView.hpp"
#include "uiView.hpp"
#include "cameraView.hpp"
#include "application.hpp"

sceneView::sceneView(application& app) 
    : view(app)
{
    scene.addObjects();
    changeSubView(subView::camera);
}

void sceneView::onEnter()
{
    currentSubView->onEnter();
}

void sceneView::handleInput()
{
    currentSubView->handleInput();
}

void sceneView::ui()
{
    currentSubView->ui();

    ImGui::SetNextWindowSize(ImVec2(300, 120));
    ImGui::Begin("Camera pos", NULL, ImGuiWindowFlags_NoResize);

    ImGui::SetNextItemWidth(150);

    if (currentCamera)
    {
        ImGui::Text("index: %d", scene.cameraMan.getIndex());
        ImGui::Text("x = %5.2f", currentCamera->getPos().x);
        ImGui::Text("y = %5.2f", currentCamera->getPos().y);
        ImGui::Text("z = %5.2f", currentCamera->getPos().z);
    }

    ImGui::End();
}

void sceneView::update(float dt)
{
    /* TODO: add animations */
    currentSubView->update(dt);
}

void sceneView::render() const
{
    scene.render();
}

void sceneView::onExit()
{
    /* remove ui callbacks */
    glfwSetCursorPosCallback(app.window.handle,  ImGui_ImplGlfw_CursorPosCallback);
    glfwSetScrollCallback(app.window.handle, ImGui_ImplGlfw_ScrollCallback);
}

sceneView::~sceneView()
{

}

void sceneView::changeSubView(subView newSubView)
{
    switch(newSubView) 
    {
    case subView::ui:
        if (currentSubView) currentSubView->onExit();
        if (!m_subViews.ui) m_subViews.ui = std::make_shared<uiView>(*this);
        currentSubView = m_subViews.ui;
        currentSubView->onEnter();
        break;
    case subView::camera:
        if (currentSubView) currentSubView->onExit();
        if (!m_subViews.camera) m_subViews.camera = std::make_shared<cameraView>(*this);
        currentSubView = m_subViews.camera;
        currentSubView->onEnter();
        break;
    }
}
