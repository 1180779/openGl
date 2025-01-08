
#include "rendering.hpp"
#include "imGuiUi.hpp"

#include "shader.hpp"
#include "shadersC.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "objectList.hpp"
#include "lightSource.hpp"

#include "cubeShape.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int, char**)
{
    rendering render = rendering();
    imGuiUi ui = imGuiUi(render);
    ui.styleLight();
    ui.styleRounded();
    render.initGL();
    glEnable(GL_DEPTH_TEST);

    shader sh(vertexSS, fragmentSS);
    objectList list(sh);

    lightSource light;
    light.setPos(glm::vec3(-5.0f, 3.0f, -7.5f));

    glm::vec3 cubePositions[10] = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    float angle = 50.f;
    for (int i = 0; i < 10; ++i) {
        angle += 50.f;
        objectShape* obj = new cubeShape();
        obj->m_material = material::copper;
        obj->m_pos = cubePositions[i];
        list.addObject(obj);
    }

    camera cam(render);
    cam.setCurrent();
    camera::disableCursor(render);
    camera::setCallbacks(render);

    // Main loop
    while (!glfwWindowShouldClose(render.window))
    {
        if (glfwGetKey(render.window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(render.window, GL_TRUE);
        }
        render.measureDeltaTime();
        cam.processInput();
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();
        if (glfwGetWindowAttrib(render.window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        ui.newFrame();
        ui.settingsWindow();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(render.window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        render.clearColor();
        glClear(GL_DEPTH_BUFFER_BIT);

        list.render(cam, light);
        light.render(cam);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        render.swapBuffers();
    }
    return 0;
}
