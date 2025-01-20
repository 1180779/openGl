
#ifndef U1180779_APPLICATION_H
#define U1180779_APPLICATION_H

#include <iostream>

#include "glad/glad.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "imGui/imgui.h"

#include "dataTypes.hpp"
#include "window.hpp"
#include "deltaTime.hpp"

#include "sceneView.hpp"

class view;
class sceneView;

class application 
{
public:

    /* structures */

    enum view 
    {
        scene,
        menu
    };

    struct views 
    {
        std::shared_ptr<sceneView> scene;
    };

    /* avaliable methods */

    application();
    void run();
    void changeView(view newView);
    ~application();

    /* public variables */

    deltaTime deltaTime;
    window window;

private:

    /* private variables */

    std::shared_ptr<::view> m_currentView;
    views m_views;
    view m_activeView = view::scene;
};

#endif