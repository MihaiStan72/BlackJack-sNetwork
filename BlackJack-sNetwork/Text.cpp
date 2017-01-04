#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>

using namespace ConcreteDrawableObjects;
using namespace UI;


Text::Text() {
}

void Text::Draw() {

	if (screenPosition.x && screenPosition.y && !path.empty()) {
		this->Draw(path, screenPosition.x, screenPosition.y);
	}
}

void Text::Draw(std::string path, float x, float y) {

	std::cout << "Desenat text";

	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Text text;
	sf::Font font;

	if (!font.loadFromFile("Resources/Fonts/arial.ttf")) {
		std::cout << "Eroare incarcare font!" << '\n';
	}
	text.setFont(font);
	text.setString(path);
	text.setCharacterSize(30); //in pixels, not points!
	text.setFillColor(sf::Color::Red);
	text.setPosition(x, y);
	window->draw(text);
}

Text::~Text() {
}
