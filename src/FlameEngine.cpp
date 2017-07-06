#include <iostream>
#include <SFML/OpenGL.hpp>
#include "system/window.h"

using namespace std;

int main() {
	cout << "Flame engine OSCPR 0.1" << endl;

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	Window window(settings);
	window.setCentered();
	while(window.isOpen()) {

		glViewport(0, 0, window.getWidth(), window.getHeight());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		window.update();
	}
}
