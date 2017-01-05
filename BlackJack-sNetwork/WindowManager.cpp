#include "UI.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>
using namespace UI;

WindowManager::WindowManager() {
	CreateWindow();
}

WindowManager::~WindowManager() {
}

sf::RenderWindow* WindowManager::getWindow(int index) {
	return windowVector.at(index);
}


void WindowManager::CreateWindow() {
	sf::RenderWindow *window = new sf::RenderWindow();
	window->create(sf::VideoMode::getDesktopMode(), "BlackJack's Network", sf::Style::Default);
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	windowVector.push_back(window);
}

void WindowManager::CloseWindow(int index) {

}

bool WindowManager::isButtonPressed() {
	
	//sf::Vector2f mousePosition;
	//sf::FloatRect global = sprite.getGlobalBounds(); dimensiunile butonului
	if (mousePosition.x > screenPosition.x && mousePosition.x < screenPosition.x + global.width
		&& mousePosition.y > screenPosition.y && mousePosition.y < screenPosition.y + global.height)
		return true;

	return false
}

int WindowManager::CheckWindowForEvents(int index) {
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	sf::RenderWindow *window = windowVector.at(index);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{	 

			if(event.mouseButton.button == (sf::Mouse::Left))
			{
				mousePosition = sf::Mouse::getPosition(*window);
				std::cout << "width: " << mousePosition.x << '\n';
				std::cout << "height: " << mousePosition.y << '\n';
				return 1;
			}

			if (event.mouseButton.button == (sf::Mouse::Right))
			{
				mousePosition = sf::Mouse::getPosition(*window);
				std::cout << "width: " << mousePosition.x << '\n';
				std::cout << "height: " << mousePosition.y << '\n';
				return 2;
			}
			if (event.mouseButton.button == (sf::Mouse::Middle))
				window->close();
		}

		if (event.type == sf::Event::Closed) /// IESI ACASA!!
		{
			window->close();
		}
	}
}

bool WindowManager::HasOpenWindows() {
	bool result = windowVector.empty();
	return !result;
}