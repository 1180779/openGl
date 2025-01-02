
#include "rendering.hpp"
#include "imGuiUi.hpp"

#include "Shaders.hpp"
#include "shadersC.hpp"

#include "triangle.hpp"

int main(int, char**)
{
    rendering render = rendering();
    imGuiUi ui = imGuiUi(render);
    render.initGL();

    shaders shaders(vertexSS, fragmentSS);
    shaders.createProgram();

    triangle triangle;

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

        triangle.render(shaders.program);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        render.swapBuffers();
    }

    shaders.deleteProgram(); 
    return 0;
}
