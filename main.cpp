#include "include.h"

#include <Windows.h>

#include "app.h"
#include "specs.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd) {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(720, 490, specs::screen_title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    App app(window);
    app.run();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}