#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(unsigned int numParticles) :
	numParticles(numParticles)
{
	particles.resize(numParticles);

	instantiateVAO();
	instantiateVBO();
}


void ParticleSystem::instantiateVAO()
{
	glGenVertexArrays(1, &particleVAO);
	glBindVertexArray(particleVAO);
}

void ParticleSystem::instantiateVBO()
{
	// 1. Generate a buffer ID for the VBO
	glGenBuffers(1, &particleVBO);
	
	// 2. Bind the VBO and set its data
	glBindBuffer(GL_ARRAY_BUFFER, particleVBO);
	glBufferData(GL_ARRAY_BUFFER, particles.size() * sizeof(Particle), &particles[0], GL_DYNAMIC_DRAW);
	
	// 3. Enable vertex attribute arrays for each attribute
	glEnableVertexAttribArray(0); // position
	glEnableVertexAttribArray(1); // velocity
	glEnableVertexAttribArray(2); // color
	glEnableVertexAttribArray(3); // force
	glEnableVertexAttribArray(4); // size
	glEnableVertexAttribArray(5); // lifetime
	
								  // 4. Specify the vertex attribute pointers
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)sizeof(glm::vec4));
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)(2 * sizeof(glm::vec4)));
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)(3 * sizeof(glm::vec4)));
	glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)(4 * sizeof(glm::vec4)));
	glVertexAttribPointer(5, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)(5 * sizeof(glm::vec4)));
}

void ParticleSystem::draw()
{
	glBindVertexArray(particleVAO);
	glDrawArrays(GL_POINTS, 0, numParticles);
}