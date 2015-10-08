#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>
#include "Transform.h"

class Shader {

public:
	Shader(const std::string&);

	void Bind();
	void Update(const Transform&);

	virtual ~Shader();
protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	enum {
		TRANSFORM_U,
		
		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

#endif
