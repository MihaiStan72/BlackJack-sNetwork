#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>
#define EnableUILogging 0

using namespace ConcreteDrawableObjects;
using namespace UI;

Button::Button(){
}

void Button::SetWidthAndHeight(float width, float height){
	width = width;
	height = height;
}

void Button::Draw(){

	if (EnableUILogging) {
		//Debugger::LogThis("inceput desenat tabla");
	}

	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Sprite sprite;
	sf::Texture texture;
	std::string path = "Resources/Photos/buton.png";

	if (!texture.loadFromFile(path)) {
		if (EnableUILogging) {
			//Debugger::LogThis("Eroare incarcare png!");
		}
	}
	sprite.setTexture(texture);
	//sprite.setTextureRect(sf::IntRect(10, 10, 100, 100));
	sprite.setScale(width, height);

	//sf::FloatRect global = sprite.getGlobalBounds();
	//std::cout << global.width << " " << global.height << '\n';

	sprite.setPosition(topLeftPosition.x, topLeftPosition.y);
	window->draw(sprite);

	if (EnableUILogging) {
		//Debugger::LogThis("Desenat tabla");
	}
}

Button::~Button() {
}
