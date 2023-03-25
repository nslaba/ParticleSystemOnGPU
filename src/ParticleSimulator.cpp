#include "ParticleSimulator.h"


ParticleSimulator::ParticleSimulator(ParticleSystem* target)
	: particles(target){

}

int ParticleSimulator::step(double time)
{
	// update particle positions and other attributes
	for (unsigned int i = 0; i < particles->numParticles; i++)
	{
		// update particle attributes
	}

	glBindBuffer(GL_ARRAY_BUFFER, particles->particleVBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, particles->numParticles * sizeof(Particle), &particles[0]);

	return 0;
}