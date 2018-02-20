#include <glad/glad.h>
#include <GLFW/glfw3.h> // opens windows and handles keyboard presses
#include <iostream>
void framebuffer_size_callback(int width, int height);
void processInput(GLFWwindow *window);

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
    glfwInit();
    GLFWWindow *window = glfwCreateWindow(SC_WIDTH, SC_HEIGHT, "MY WINDOW", NULL, NULL);
    if (window == NULL) {
        cout << "error in window creation" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // create some shaders
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);
    glCompileShader(vertexShader); // shaders could go wrong, can call glGetShader function to get error messages
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragentShader);

    float vertices[9]{
         0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.0f,
         0.5f, -0.5f,  0.0f,
    };
    unsigned int buffer;
    glGenBuffers(1, buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer)
    glBufferData(buffer, sizeof(buffer), vertices, GL_STATIC_DRAW);

    // render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(0.2, 0.2, 0.2, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glDrawArrays(GL_POINT, 0, 9);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteBuffers(1, &buffer);
    glfwTerminate();
    return 1;
}
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback (int width, int height) {
    glViewport(0,0,width,height);
}