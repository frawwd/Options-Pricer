#include "app.h"

#include "specs.h"


App::App(GLFWwindow* window) : m_Window(window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

App::~App() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void App::run() {
    while (!glfwWindowShouldClose(m_Window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a dockspace that covers the entire viewport
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        // Begin the dockspace window
        ImGui::Begin("DockSpace", nullptr, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus);

        // Create the dockspace
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

        // End the dockspace window
        ImGui::End();

        // Example window
        window();
        ImGui::ShowDemoWindow(&demo_window);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(m_Window);
    }
}

void App::window() {
    ImGui::Begin(specs::screen_title);

    ImGui::Text("Call Prices %f", opt.call_price);
    ImGui::Text("Put Prices %f", opt.put_price);

    ImGui::Separator();

    ImGui::InputFloat("Current Asset Price", &opt.current_asset_price);
    ImGui::InputFloat("Strike Price", &opt.strike_price);
    ImGui::InputFloat("Time To Maturity (Years)", &opt.time_to_maturity);
    ImGui::InputFloat("Volitilaty", &opt.volatility);
    ImGui::InputFloat("Risk Free Intrest", &opt.risk_free_intrest);

    if (ImGui::Button("Calculate Prices")) {
        opt.calc_d1();
        opt.calc_d2();
        opt.calc_call_price();
        opt.calc_put_price();
    }

    long long int luke;

    ImGui::End();
}
