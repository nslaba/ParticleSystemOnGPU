#pragma once
/*
 *
 *
 * The point of this class is to create a buffer of particles using a Vertex Buffer Object, binding it and setting the particle data that can then be passed to a vertex
 * Shader for rendering
 *
 */
#include <./../../../../GPUParticles/GPUParticles/external/include/glad/glad.h>
#include <./../../../../GPUParticles/GPUParticles/external/GLFW/glfw-3.3.8.bin.WIN32/include/GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Particle.h"




class ParticleSystem {
public:
	ParticleSystem(unsigned int numParticles);
	unsigned int numParticles;
	GLuint getParticleVBO();
	GLuint getParticleVAO();
	void draw();
	GLuint particleVBO;
	GLuint particleVAO;
	std::vector<Particle> particles;
private:
	
	
	
	

	void instantiateVBO();
	void instantiateVAO();
};
	
