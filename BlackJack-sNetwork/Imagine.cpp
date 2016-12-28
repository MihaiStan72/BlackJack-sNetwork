#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>

using namespace ConcreteDrawableObjects;
using namespace UI;


Imagine::Imagine(){
}

void Imagine::Draw() {
	std::cout << "Desenat tabla";
	
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
}

void Imagine::Draw(char path[100], int x, int y)
{
	std::cout << "Desenat carte";

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
}

Imagine::~Imagine(){
}
