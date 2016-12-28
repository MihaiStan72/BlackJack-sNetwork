#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>

using namespace ConcreteDrawableObjects;
using namespace UI;


Imagine::Imagine(){
}

void Imagine::Draw() {
	std::cout << "Desenat Imagine";
	
	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Sprite sprite;
	sf::Texture texture;
	std::string path = "D:/BlackJack-sNetwork/BlackJack-sNetwork/x64/Debug/Resources/Photos/table_ps.png";
	
	if (!texture.loadFromFile(path)) {
		std::cout << "Eroare incarcare png!" << '\n';
	}

	sprite.setTexture(texture);
	int centredSprite_x = (window->getSize().x - sprite.getLocalBounds().width) / 2;
	int centredSprite_y = (window->getSize().y - sprite.getLocalBounds().height) / 2;
	sprite.setPosition(centredSprite_x, centredSprite_y);
	window->draw(sprite);
}

Imagine::~Imagine(){
}
