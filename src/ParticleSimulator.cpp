#include "ParticleSimulator.h"


ParticleSimulator::ParticleSimulator(ParticleSystem* target)
	: particleSystem(target){

}

int ParticleSimulator::step(double time)
{
	// update particle positions and other attributes
	for (unsigned int i = 0; i < particleSystem->numParticles; i++)
	{
		// update particle attributes
		particleSystem->particles[i].color = { 1.0, 0.0, 0.1, 1.0 };
		particleSystem->particles[i].force = { 0.0, 0.0, 0.0, 0.0 };
		particleSystem->particles[i].lifetime = 20.0;
		particleSystem->particles[i].position = { (float)i/2.0, (float)i/2.0, (float)i/2.0, 1 };
		particleSystem->particles[i].size = 40.0;
		particleSystem->particles[i].velocity = { 0.0, 0.0, 0.0, 0 };
	}
	glBindBuffer(GL_ARRAY_BUFFER, particleSystem->particleVBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, particleSystem->numParticles * sizeof(Particle), &particleSystem->particles.front());

	return 0;
}