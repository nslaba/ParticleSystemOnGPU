#include "ShaderHandler.h"
#include "ParticleSimulator.h"
#include "Processing.h"
//#include <../../../../../../PROJECT/project/GPUParticles/GPUParticles/external/GLFW/glfw-3.3.8.bin.WIN32/include/GLFW/glfw3.h>
#include <iostream>

int main() {
	/* STEP 1: compile the Processing sketch*/
	std::string sketchPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\src\processingSketch\HermiteSplineSketch_pde";
	std::string outputPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\output";
	Processing* processingHandler;
	processingHandler->buildSketch(sketchPath, outputPath);

	/*STEP 2: deal with display*/
	
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Set OpenGL version to 4.6
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	// Create a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "My Window", nullptr, nullptr);
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make the context of the window the current one
	glfwMakeContextCurrent(window);

	// Initialize GLAD to load OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set the screen color to green
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();

	}

	// Clean up GLFW
	glfwTerminate();

	return 0;
}