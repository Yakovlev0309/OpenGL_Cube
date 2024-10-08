#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "cube/cube.h"

const int window_width = 800;
const int window_height = 800;

double start_x = 0;
double start_y = 0;
double x = 0;
double y = 0;

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Cube", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    Cube::setupGraphics(window_width, window_height);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
        {
            glfwGetCursorPos(window, &start_x, &start_y);
        }
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        {
            glfwGetCursorPos(window, &x, &y);
            Cube::rotate(x - start_x, y - start_y);
        }

        Cube::renderFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Cube::destroy();
    glfwTerminate();
    return 0;
}
