#include "include.h"

#include "app.h"
#include "specs.h"

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1280, 720, specs::screen_title, NULL, NULL);
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