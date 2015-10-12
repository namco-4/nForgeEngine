#version 120

uniform sampler2D diffuse;

varying vec2 texCoord0;
varying vec3 normal0;

void main() {
	float skalar = clamp(dot(vec3(0, 0, -1), normalize(normal0)), 0.0, 1.0);
	gl_FragColor = skalar * texture2D(diffuse, texCoord0);
}