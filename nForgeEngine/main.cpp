#include <iostream>
#include <GL\glew.h>
#include "Display.h"

using namespace std;

int main(int argc, char* argv[]) {
	Display display(1280, 720, "Hello World!");

	while (!display.isClosed()) {
		display.Clear(0.33f, 0.33f, 0.66f, 1.0f);
		display.Update();
	}

	return 0;
}