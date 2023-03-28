#version 460

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 velocity;
layout(location = 2) in vec4 color;
layout(location = 3) in vec4 force;
layout(location = 4) in float size;
layout(location = 5) in float lifetime;

uniform mat4 projectionMatrix; // uniforms need to be passed to shader in my code
uniform mat4 viewMatrix;

out vec4 fragmentColor;

void main()
{

	// Calculate the particle's position
	vec3 pos = position.xyz + velocity.xyz * lifetime + 0.5 * force.xyz * lifetime * lifetime;

	// Apply the view and projection matrices
	gl_Position = projectionMatrix * viewMatrix * vec4(pos, 1.0);

	// Set the particle's size
	gl_PointSize = size;

	// Pass the particle's color to the fragment shader
	fragmentColor = color;
}