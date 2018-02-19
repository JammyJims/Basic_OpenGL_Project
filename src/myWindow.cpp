#include <glad/glad.h>
#include <GLFW/glfw3.h> // opens windows and handles keyboard presses
#include <iostream>
void framebuffer_size_callback(int width, int height);

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.0f, 0.0f, 0.0f, 0.5f);\n"
                                   "}\n\0";
const int SC_HEIGHT = 800;
const int SC_WIDTH = 800;
int main() {
    using namespace std;
    float vertices[9] {
         0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
    };
    glfwInit();
    GLFWWindow *window = glfwCreateWindow(SC_WIDTH, SC_HEIGHT, "MY WINDOW", NULL, NULL);
    if (window == NULL) {
        cout << "error in window creation" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
void framebuffer_size_callback (int width, int height) {
    glViewport(0,0,width,height);
}