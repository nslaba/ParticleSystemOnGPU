#pragma once
#include <./../../../../GPUParticles/GPUParticles/external/glm/glm.hpp>
#include <./../../../../GPUParticles/GPUParticles/external/glm/gtc/matrix_transform.hpp>
#include <./../../../../GPUParticles/GPUParticles/external/glm/gtc/type_ptr.hpp>

// Particle struct
struct Particle
{
	glm::vec4 position, velocity, color, force;
	float size, lifetime; // size in pixels

};