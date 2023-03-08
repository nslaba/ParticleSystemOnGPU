#version 460

out vec4 fragColor;

void main()
{
	fragColor = vec4(gl_FragCoord.xyz / 800.0, 1.0);
}