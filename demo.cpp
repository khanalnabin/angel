#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "Angel.hpp"

void handleInput(GLFWwindow *window);
void framebufferSizeCallback(GLFWwindow *window, int width, int height);

int main() {

	// initialize GLFW
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW." << std::endl;
		return -1;
	}
	std::cout << "Initialized GLFW." << std::endl;

	// // Set window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a window
	GLFWwindow *window =
	    glfwCreateWindow(600, 600, "opengl-triangle", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window!" << std::endl;
		return -1;
	}
	std::cout << "Window created." << std::endl;
	glfwMakeContextCurrent(window);

	// load glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Unable to initialize glad!" << std::endl;
		return -1;
	}
	std::cout << "Loaded GLAD." << std::endl;

	// setup Angel
	Angel::init(600, 600);

	while (!glfwWindowShouldClose(window)) {
		handleInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		Angel::putPixel(100, 100, 10);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void handleInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_Q))
		glfwSetWindowShouldClose(window, true);
}
void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}
