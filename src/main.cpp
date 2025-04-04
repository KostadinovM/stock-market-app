#include <imgui.h>
#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>    // Include ImGui GLFW backend
#include <imgui_impl_opengl3.h> // Include ImGui OpenGL3 backend
#include <iostream>
#include <cstdlib> // For std::exit

void renderLoop(GLFWwindow *window)
{
    bool showMainWindow = true;

    while (!glfwWindowShouldClose(window))
    {
        // Poll events
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (showMainWindow)
        {
            ImGui::Begin("Main Window", &showMainWindow);
            if (ImGui::Button("Click Me"))
            {
                std::cout << "Button clicked!" << std::endl;
            }
            ImGui::End();
        }

        // Render ImGui
        ImGui::Render();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ImGui draw data
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }
}

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return EXIT_FAILURE;
    }

    // Create a GLFW window
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Stock Market App", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();

    // Initialize ImGui for OpenGL and GLFW
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Set a valid DisplaySize
    io.DisplaySize = ImVec2(1280.0f, 720.0f);

    // Build the font atlas
    unsigned char *texPixels = nullptr;
    int texWidth = 0, texHeight = 0, texBytesPerPixel = 0;
    io.Fonts->GetTexDataAsRGBA32(&texPixels, &texWidth, &texHeight, &texBytesPerPixel);

    // Log texture information (optional)
    std::cout << "Font texture generated: " << texWidth << "x" << texHeight
              << " (" << texBytesPerPixel << " bytes per pixel)" << std::endl;

    // Enter the render loop
    renderLoop(window);

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}