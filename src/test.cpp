#include <iostream>
#include <glad/glad.h> // library for calling OpenGL function calls
#include <GLFW/glfw3.h> // 

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    std::cout << "hello world" << std::endl;

    // initialise GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "failed to initialise GLAD" << std::endl;
        return -1;
    }


    // create a window
    GLFWwindow *window = glfwCreateWindow(800,600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;;
        glfwTerminate();
        return -1;
    }

    // create viewport
    glViewport(0,0,800,600);
    GLFWframebuffersizefun(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);
    
    // keep the rendered window open
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}