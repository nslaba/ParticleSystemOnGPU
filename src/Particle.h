#pragma once
#include <./../../../../GPUParticles/GPUParticles/external/glm/glm.hpp>

// Particle struct
struct Particle
{
	glm::vec4 position, velocity, color, force;
	float size, lifetime; // size in pixels

};