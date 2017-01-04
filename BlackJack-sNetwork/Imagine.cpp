#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>

using namespace ConcreteDrawableObjects;
using namespace UI;


Imagine::Imagine(){
}

void Imagine::Draw(){

	if (screenPosition.x && screenPosition.y && !path.empty()) {
		this->Draw(path, screenPosition.x, screenPosition.y);
	}
	else {
		std::cout << "inceput desenat tabla" << '\n';
		sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = "Resources/Photos/table_ps.png";

		if (!texture.loadFromFile(path)) {
			std::cout << "Eroare incarcare png!" << '\n';
		}
		sprite.setTexture(texture);
		int centredSprite_x = (window->getSize().x - sprite.getLocalBounds().width) / 2;
		int centredSprite_y = (window->getSize().y - sprite.getLocalBounds().height) / 2;
		sprite.setPosition(centredSprite_x, centredSprite_y);
		window->draw(sprite);
		std::cout << "Desenat tabla" << '\n';
	}
}

void Imagine::Draw(std::string path, float x, float y){
	
	
	std::cout << "inceput desenat carte" << '\n';
	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Sprite sprite;
	sf::Texture texture;

	if (!texture.loadFromFile(path)) {
		std::cout << "Eroare incarcare png!" << '\n';
	}
	sprite.setTexture(texture);
	sprite.setScale(0.25f, 0.25f);
	sprite.setPosition(x, y);
	window->draw(sprite);
	std::cout << "Desenat carte" << '\n';
}

Imagine::~Imagine(){
}
