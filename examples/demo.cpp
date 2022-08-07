#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

#include "Angel.hpp"

int WIDTH = 800;
int HEIGHT = 800;

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
	    glfwCreateWindow(WIDTH, HEIGHT, "opengl-triangle", NULL, NULL);
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

	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// setup Angel
	Angel::init(WIDTH, HEIGHT);

	while (!glfwWindowShouldClose(window)) {
		handleInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// axes
		Angel::drawAxes();

		// octants
		Angel::line(0, 0, WIDTH / 2, HEIGHT / 2);
		Angel::line(0, 0, WIDTH / 2, -HEIGHT / 2);
		Angel::line(0, 0, -WIDTH / 2, HEIGHT / 2);
		Angel::line(0, 0, -WIDTH / 2, -HEIGHT / 2);

		// sine, cosine and tangent curves
		for (int i = (-WIDTH / 2); i <= WIDTH / 2; i++) {
			float radians = -2 * M_PI + (i + (float)WIDTH / 2) /
			                                ((float)WIDTH) * (M_PI * 2 * 2);
			Angel::putPixel(i, 100 * sin(radians), Color(1.0f, 0.0f, 0.0f));
			Angel::putPixel(i, 100 * cos(radians), Color(0.0f, 1.0f, 0.0f));
			Angel::putPixel(i, 100 * tan(radians), Color(0.0f, 0.0f, 1.0f));
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void handleInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_Q))
		glfwSetWindowShouldClose(window, true);
}
void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
	WIDTH = width;
	HEIGHT = height;
	glViewport(0, 0, width, height);
	Angel::setWidth(width);
	Angel::setHeight(height);
}
