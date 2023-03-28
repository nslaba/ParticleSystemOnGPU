#include <windows.h>
#include <winerror.h>
#include "ShaderHandler.h"
#include "ParticleSimulator.h"
#include "Processing.h"
//#include <../../../../../../PROJECT/project/GPUParticles/GPUParticles/external/GLFW/glfw-3.3.8.bin.WIN32/include/GLFW/glfw3.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>


int main() {



	// DECLARE SHADERS
	std::string vertexShaderPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\src\shaders\vertexShader.glsl";
	std::string fragmentShaderPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\src\shaders\FragmentShader.glsl";

	std::cout << "vertShPath is: " << vertexShaderPath << "\n";
	std::cout << "fragShPath is: " << fragmentShaderPath << "\n";

	//const char* vertexShaderPath = "C:/Users/slaba/Desktop/uvic degree/comp csi/";
	//const char* fragmentShaderPath = ".\\..\\GPUParticles\\src\\shaders\\FragmentShader.glsl";

	// Create shader object
	ShaderHandler displayShader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

	// Use this shader before rendering particles
	displayShader.use();

	// SET UP VIEW AND PROJECTION MATRICES
	glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f); // 800 and 600 are window width and height resp

	// Get the location of the viewMatrix and projectionMatrix Uniforms
	GLuint viewMatrixLocation = glGetUniformLocation(displayShader.getProgramID(), "viewMatrix");
	GLuint projectionMatrixLocation = glGetUniformLocation(displayShader.getProgramID() , "projectionMatrix");

	// Pass Matrices as uniforms once I have location
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix)); //passes the matrices as 4x4 float matrices with transpose flag set to false and with data taken from glm obj
	

	/* STEP 1: compile the Processing sketch*/
	/*std::string sketchPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\src\processingSketch\HermiteSplineSketch_pde";
	std::string outputPath = "C:\\Users\slaba\Desktop\\uvic degree\comp sci\CSC 473\PROJECT\project\GPUParticles\GPUParticles\output";
	Processing* processingHandler;
	processingHandler->buildSketch(sketchPath, outputPath);*/


	/* STEP 1: create a particle system to be drawn*/

	// Create a particle system
	ParticleSystem particleSystem(100000); // instantiates VBO in the constructor

	// Create a particle simulator
	ParticleSimulator particleSimulator(&particleSystem);

	



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
		/* PARTICLE DISPLAY*/

		// Update the particles
		particleSimulator.step(0.1);


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