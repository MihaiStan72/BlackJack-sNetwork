#include "UI.h"

using namespace UI;

WindowManager::WindowManager() {
	CreateWindow();
}

WindowManager::~WindowManager() {

}

void WindowManager::CreateWindow() {
	sf::RenderWindow *window = new sf::RenderWindow();
	window->create(sf::VideoMode::getDesktopMode(), "BlackJack's Network", sf::Style::Default);
	windowList.push_back(window);
}

void WindowManager::CloseWindow(int index) {

}