
#include "rendering.hpp"
#include "imGuiUi.hpp"

#include "shader.hpp"
#include "shadersC.hpp"
#include "texture.hpp"

#include "triangle.hpp"
#include "rectangle.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int, char**)
{
    rendering render = rendering();
    imGuiUi ui = imGuiUi(render);
    ui.styleLight();
    ui.styleRounded();
    render.initGL();

    texture t1("textures/woodencontainer.jpg"), t2("textures/awesomeface.png", GL_RGBA);
    shader sh(vertexSS5, fragmentSS4);
    sh.use();
    sh.set1i("texture1", 0);
    sh.set1i("texture2", 1);

    const object& obj = rectangle();

    // Main loop
    while (!glfwWindowShouldClose(render.window))
    {
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

        t1.use();
        t2.use(1);
        sh.use();

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)));
        sh.setMatrix4fv("transform", trans);

        obj.render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        render.swapBuffers();
    }
    return 0;
}
