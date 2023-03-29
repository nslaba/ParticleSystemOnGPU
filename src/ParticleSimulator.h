#pragma once

#include "ParticleSystem.h"
#include <./../../../../GPUParticles/GPUParticles/external/include/glad/glad.h>
#include <./../../../../GPUParticles/GPUParticles/external/GLFW/glfw-3.3.8.bin.WIN32/include/GLFW/glfw3.h>

class ParticleSimulator {
public:

	ParticleSimulator(ParticleSystem* target);


	int step(double u_time);
	

private:

	ParticleSystem* particleSystem;
};