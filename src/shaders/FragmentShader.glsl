#version 460

// Input vertex attributes
layout (location = 0) in vec4 position; // position.xyz: particle position; position.w: particle size
layout (location = 1) in vec4 color;    // particle color
layout (location = 2) in float lifetime;// remaining lifetime of particle

// Output fragment color
out vec4 fragColor;

// Uniforms
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
	// Calculate the model matrix (identity for particles)
	mat4 modelMatrix = mat4(1.0);
	modelMatrix = translate(modelMatrix, position.xyz);
	modelMatrix = scale(modelMatrix, vec3(position.w));

	// Calculate the final MVP matrix
	mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

	// Pass the color to the fragment shader
	fragColor = color;

	// Discard particles with negative lifetime
	if (lifetime < 0.0)
		discard; // discard is a keyword in glsl to discard the fragment

	// Output the vertex position
	gl_Position = mvpMatrix * vec4(0.0, 0.0, 0.0, 1.0);

}