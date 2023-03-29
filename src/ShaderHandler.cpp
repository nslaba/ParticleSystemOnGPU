#include "ShaderHandler.h"

ShaderHandler::ShaderHandler(std::string VertexShaderPath, std::string fragmentShaderPath)
{
	//Load and compile vertex shader
	std::string vertexShaderSource = loadShaderFile(VertexShaderPath);
	const char* vertexShaderSourcePtr = vertexShaderSource.c_str();
	// create vertex shader object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSourcePtr, nullptr);
	glCompileShader(vertexShader);
	checkShaderCompilationErrors(vertexShader);

	//Load and compile fragment shader
	std::string fragmentShaderSource = loadShaderFile(fragmentShaderPath);
	const char* fragmentShaderSourcePtr = fragmentShaderSource.c_str();
	//create fragment shader object
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSourcePtr, nullptr);
	glCompileShader(fragmentShader);
	checkShaderCompilationErrors(vertexShader);

	//Create shader program object, attach shaders, and link
	m_program = glCreateProgram();
	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);
	glLinkProgram(m_program);
	checkShaderCompilationErrors(m_program);

	// keep track of current shader program
	m_currentProgram = m_program;
	

}

GLuint ShaderHandler::getProgramID()
{
	if (m_currentProgram != m_program)
	{
		throw std::runtime_error("trying to use a new program that isn't current program");
	}
	else {
		return m_program;
	}
	
}
std::string ShaderHandler::loadShaderFile(std::string filename) {
	

	try {
		std::ifstream file(filename);
		if (!file) {
			throw std::runtime_error("Failed to open file: " + std::string(filename));
		}
	
	
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	return buffer.str();
	}
	catch  (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;

	}
	return "";
}

void ShaderHandler::use() {
	//only call glUseProgram if the current shader program ID is different
	if (m_currentProgram != m_program) {
		glUseProgram(m_program);
		m_currentProgram = m_program;
	}
}
void ShaderHandler::checkShaderCompilationErrors(GLuint shader) {
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "Error: shader compilation failed\n" << infoLog << std::endl;
	}
}

void ShaderHandler::checkProgramLinking(GLuint program) {
	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cerr << "Error: program linking failed\n" << infoLog << std::endl;
	}
}