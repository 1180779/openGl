
#include "imGuiUi.hpp"

imGuiUi::imGuiUi(rendering& rendering) : _rendering(rendering), io((ImGui::CreateContext(), ImGui::GetIO()))
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(_rendering.window, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(window, "#canvas");
#endif
    ImGui_ImplOpenGL3_Init(_rendering.glsl_version);
}

imGuiUi::~imGuiUi()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void imGuiUi::settingsWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 80));
    ImGui::Begin("Dynamic settings", NULL, ImGuiWindowFlags_NoResize);

    ImGui::SetNextItemWidth(150);
    ImGui::ColorEdit3("Change background", (float*)&_rendering.clear_color); // Edit 3 floats representing a color

    ImGui::Text("Average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();
}

void imGuiUi::newFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
