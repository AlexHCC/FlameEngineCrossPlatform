#include "window.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

Window::Window(sf::ContextSettings settings, int width, int height, string title, bool resizable, bool fullscreen) {
	if (resizable && fullscreen) {window.create(sf::VideoMode(width, height), title, sf::Style::Default | sf::Style::Resize | sf::Style::Fullscreen, settings);}
	else if (resizable) {window.create(sf::VideoMode(width, height), title, sf::Style::Default | sf::Style::Resize, settings);}
	else if (fullscreen) {window.create(sf::VideoMode(width, height), title, sf::Style::Default | sf::Style::Fullscreen, settings);}
	else {window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);}
}

int Window::getWidth() {return window.getSize().x;}
int Window::getHeight() {return window.getSize().y;}
bool Window::isOpen() {return isOpened;}

void Window::update(int red, int green, int blue) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			isOpened = false;
	}
	window.clear(sf::Color(red,green,blue));
	//sf::CircleShape shape(50);
	//shape.setFillColor(sf::Color(150, 50, 250));
	//window.draw(shape);
	window.display();
}

void Window::close() {isOpened = false; window.close();}
void Window::setFrameRateLimit(uint limit) {window.setFramerateLimit(limit);}
void Window::setVsync(bool vsync) {window.setVerticalSyncEnabled(vsync);}
void Window::setActive(bool isActive) {window.setActive(isActive);}
void Window::setImage(int width, int height, const unsigned char* pixels) {window.setIcon(width, height, pixels);}
void Window::setTitle(string title) {window.setTitle(title);}
void Window::setSize(int width, int height) {window.setSize(sf::Vector2u(width,height));}
void Window::setPosition(int x, int y) {window.setPosition(sf::Vector2i(x,y));}
void Window::setCentered() {
	float x = sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2;
	float y = sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2;
	window.setPosition(sf::Vector2i(x,y));
}
void Window::setJoystickThreshold(float sensitivity) {window.setJoystickThreshold(sensitivity);}
void Window::setKeyPressRepeat(bool repeat) {window.setKeyRepeatEnabled(repeat);}
void Window::setMouseVisible(bool visible) {window.setMouseCursorVisible(visible);}
