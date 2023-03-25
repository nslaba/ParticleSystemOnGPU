#version 460


out vec4 fragColor;

uniform vec2 u_resolution;

float rand(float n){
	return fract(sin(n) * 43758.5453123);
}

float noise(vec2 n){
	const vec2 d = vec2(0.0, 1.0);
	// smoothstep is a built in funtion in GLSL. Takes in low high and a val to interpolate between them. returns [0,1]
	vec2 b = floor(n), f = smoothstep(vec2(0.0), vec2(1.0), fract(n));
	return mix(mix(rand(dot(b, vec2(1.0, 1.0))),
					rand(dot(b + d.xy, vec2(1.0, 1.0))), f.x),
				mix(rand(dot(b + d.yx, vec2(1.0, 1.0))),
					rand(dot(b + d.xx, vec2(1.0, 1.0))), f.x), f.y);


}

float perlin(vec2 p) {
	return noise(p);
}

// Main function

void main(){

	// Get the current pixel position
	vec2 uv = gl_FragCoord.xy / u_resolution;
	// Store it into the r channel
	fragColor = vec4(perlin(uv * 10.0), 0.0, 0.0, 1.0);

}