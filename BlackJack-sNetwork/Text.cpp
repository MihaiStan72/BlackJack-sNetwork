#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>

using namespace ConcreteDrawableObjects;
using namespace UI;


Text::Text() {
}

void Text::Draw() {

	if (topLeftPosition.x && topLeftPosition.y && !path.empty()) {
		this->Draw(path, topLeftPosition.x, topLeftPosition.y);
	}
}

void Text::SetTextDimm(float dimm){
	
	textDimm = dimm;
}

void Text::Draw(std::string path, float x, float y) {

	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Text text;
	sf::Font font;

	if (!font.loadFromFile("Resources/Fonts/arial.ttf")) {
		std::cout << "Eroare incarcare font!" << '\n';
	}
	text.setFont(font);
	text.setString(path);
	text.setCharacterSize(textDimm); //in pixels, not points!
	text.setFillColor(sf::Color::Red);
	text.setPosition(x, y);
	window->draw(text);
}

Text::~Text() {
}
