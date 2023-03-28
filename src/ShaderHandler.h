#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

#include </../../Users/slaba/Desktop/uvic degree/comp sci/CSC 473/PROJECT/OpenGl 4.6, GLSL & Cpp/ParticleSystemOnGPUOpenGL/ParticleSystemOnGPUOpenGL/external/include/glad/glad.h>

class ShaderHandler
{
public:
	ShaderHandler(const char* vertexShaderPath, const char* fragmentShaderPath);
	void use();

	GLuint getProgramID();

private:
	GLuint m_program;
	GLuint m_currentProgram;

	std::string loadShaderFile(const char* filename);
	void checkShaderCompilationErrors(GLuint shader);
	void checkProgramLinking(GLuint program);
};