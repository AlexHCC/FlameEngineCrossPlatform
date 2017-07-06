#ifndef SYSTEM_WINDOW_H_
#define SYSTEM_WINDOW_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class Window {
private:
	bool isOpened = true;
protected:
	sf::RenderWindow window;
public:
	Window(sf::ContextSettings settings = sf::ContextSettings(32), int width = 1920/4*3, int height = 1080/4*3, string title = "Flame engine", bool resizable = false, bool fullscreen = false);
	int getWidth();
	int getHeight();
	bool isOpen();

	void update(int red = 20, int green = 20, int blue = 20);
	void close();

	void setFrameRateLimit(uint limit);
	void setVsync(bool vsync);
	void setActive(bool isActive);

	void setImage(int width, int height, const unsigned char* pixels);
	void setTitle(string title);
	void setSize(int width, int height);
	void setPosition(int x, int y);
	void setCentered();

	void setJoystickThreshold(float sensitivity);
	void setKeyPressRepeat(bool repeat);
	void setMouseVisible(bool visible);
};

#endif /* SYSTEM_WINDOW_H_ */
