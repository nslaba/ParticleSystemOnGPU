#version 460

// input variables for vertex shader (used to link the input variables to specific attributes in VBO):
// for position:
layout(location = 0) in vec3 position;
// for the texture coordinate:
layout(location = 1) in vec2 texcoord;

out vec2 v_texcoord;

uniform mat4 u_modelViewProjectionMatrix;
uniform float u_time;
uniform sampler2D u_perlinTexture;

// for now make speed a constant
const float PARTICLE_SPEED = 0.2;



void main(){
	// get the red channel (r). Since the texture only contains a single channel, the value is stored in the red channel
	vec2 perlin = vec2(
		texture(u_perlinTexture, texcoord + vec2(0.01, 0.0)).r,
		texture(u_perlinTexture, texcoord + vec2(0.0, 0.01)).r
	) * 2.0 - 1;
	// Normalize the gradient to get a unit vector:
	perlin = normalize(perlin);

	vec3 pos = position + vec3(perlin * PARTICLE_SPEED * u_time, 0.0);
	gl_Position = u_modelViewProjectionMatrix * vec4(pos, 1.0);

	v_texcoord = texcoord;
}