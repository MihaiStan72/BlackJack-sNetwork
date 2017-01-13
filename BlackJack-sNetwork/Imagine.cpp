#include "ConcreteDrawableObjects.h"
#include <iostream>
#include <string>
//#include "debug.h"
#define EnableUILogging 0

using namespace ConcreteDrawableObjects;
using namespace UI;


Imagine::Imagine() {
	hasLoadedTexture = false;
	texture = sf::Texture();
}

void Imagine::Draw(){

	if (topLeftPosition.x && topLeftPosition.y && !path.empty()) {
		this->Draw(path, topLeftPosition.x, topLeftPosition.y);
	}
	else {
		if (EnableUILogging) {
			//Debugger::LogThis("inceput desenat tabla");
		}
		sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
		sf::Sprite sprite;
		std::string path = "Resources/Photos/table_ps.png";
		if (!hasLoadedTexture) {
			texture.loadFromFile(path);
			if (!texture.loadFromFile(path)) {
				if (EnableUILogging) {
					//Debugger::LogThis("Eroare incarcare png!");
				}
			}
			hasLoadedTexture = true;
		}
		//std::cout << clock.getElapsedTime().asSeconds() << " ";
		sprite.setTexture(texture);
		//std::cout << clock.getElapsedTime().asSeconds() << " ";
		int centredSprite_x = (window->getSize().x - sprite.getLocalBounds().width) / 2;
		int centredSprite_y = (window->getSize().y - sprite.getLocalBounds().height) / 2;
		sprite.setPosition(centredSprite_x, centredSprite_y);
		window->draw(sprite);
		if (EnableUILogging) {
			//Debugger::LogThis("Desenat tabla");
		}
	}
}

void Imagine::Draw(std::string path, float x, float y){
	
	if (EnableUILogging) {
		//Debugger::LogThis("inceput desenat carte");
	}
	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	sf::Sprite sprite;
	sf::Texture texture;

	if (!texture.loadFromFile(path)) {
		if (EnableUILogging) {
			//Debugger::LogThis("Eroare incarcare png!");
		}
	}
	sprite.setTexture(texture);
	sprite.setScale(0.25f, 0.25f);
	sprite.setPosition(x, y);
	window->draw(sprite);
	if (EnableUILogging) {
		//Debugger::LogThis("Desenat carte");
	}
}

Imagine::~Imagine(){
}
