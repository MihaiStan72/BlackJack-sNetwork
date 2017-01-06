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
	sf::RenderWindow *window = windowVector.at(index);
	window->close();
	windowVector.erase(windowVector.begin() + index);
}

WindowManager::WindowEvent WindowManager::CheckWindowForEvents(int index) {
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	sf::RenderWindow *window = windowVector.at(index);
	if (window == NULL) {
		return WindowEvent::Close;
	}
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{	 

			if(event.mouseButton.button == (sf::Mouse::Left))
			{
				mousePosition = sf::Mouse::getPosition(*window);
				std::cout << "width: " << mousePosition.x << '\n';
				std::cout << "height: " << mousePosition.y << '\n';
				return WindowEvent::LeftClick;
			}

			if (event.mouseButton.button == (sf::Mouse::Right))
			{
				mousePosition = sf::Mouse::getPosition(*window);
				std::cout << "width: " << mousePosition.x << '\n';
				std::cout << "height: " << mousePosition.y << '\n';
				return WindowEvent::RightClick;
			}
			if (event.mouseButton.button == (sf::Mouse::Middle)) {
				CloseWindow(index);
				return WindowEvent::Close;
			}
				
		}

		if (event.type == sf::Event::Closed) {
			CloseWindow(index);
			return WindowEvent::Close;
		}
	}
	return WindowEvent::NoEvent;
}

bool WindowManager::HasOpenWindows() {
	for each (sf::RenderWindow* var in windowVector) {
		if (var->isOpen()) {
			return true;
		}
	}
	return false;
}