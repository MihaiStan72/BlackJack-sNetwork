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
	windowVector.push_back(window);
}

void WindowManager::CloseWindow(int index) {

}

void WindowManager::CheckWindowForEvents(int index) {
	/// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	sf::RenderWindow *window = windowVector.at(index);
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))///afiseaza alta pereche de carti
			{
				//show_cards();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))///afiseaza coordonatele click-ului
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
				std::cout << "width: " << localPosition.x << '\n';
				std::cout << "height: " << localPosition.y << '\n';
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
				window->close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			//chip.move()

			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))*/
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