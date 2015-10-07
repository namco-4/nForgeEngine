#include <iostream>
#include <GL\glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

using namespace std;

int main(int argc, char** argv) {
	Display display(1280, 720, "Hello World!");
	Vertex vertices[] = { Vertex(glm::vec3(-0.5f, -0.5f, 0),glm::vec2(0.0,1.0)),
							Vertex(glm::vec3(0, 0.5f, 0),glm::vec2(0.5,0.0)),
							Vertex(glm::vec3(0.5f, -0.5f, 0),glm::vec2(1.0,1.0))};
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/testImage.jpg");

	while (!display.isClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		texture.Bind(0);
		mesh.Draw();

		display.Update();
	}

	return 0;
}