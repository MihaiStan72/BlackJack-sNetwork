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

void Imagine::Draw() {

	int ok = 1;
	sf::Sprite sprite;
	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);


	if (topLeftPosition.x && topLeftPosition.y && !path.empty()) {
		this->Draw(path, topLeftPosition.x, topLeftPosition.y);
	}
	else {

		if (topLeftPosition.x == -1 && topLeftPosition.y == -1 && path.empty()) {
			ok = 0;
		}
		else {
			if (topLeftPosition.x == 50 && topLeftPosition.y == 650 && path.empty()) {
				ok = 2;
			}
		}

		if (EnableUILogging) {
			//Debugger::LogThis("inceput desenat tabla");
		}			
		
		if (ok == 1) {
			path = "Resources/Photos/table_ps.png";
		}

		if (ok == 2) {
			path = "Resources/Photos/chips.png";
		}
		if (ok == 0){
			path = "Resources/Photos/coverBJ.png";
		}

	if (!hasLoadedTexture) {
			texture.loadFromFile(path);
			if (!texture.loadFromFile(path)) {
				if (EnableUILogging) {
					//Debugger::LogThis("Eroare incarcare png!");
				}
			}
			hasLoadedTexture = true;
		}

		if (ok != 2) {

			//std::cout << clock.getElapsedTime().asSeconds() << " ";
			sprite.setTexture(texture);
			//std::cout << clock.getElapsedTime().asSeconds() << " ";
			int centredSprite_x = (window->getSize().x - sprite.getLocalBounds().width) / 2;
			int centredSprite_y = (window->getSize().y - sprite.getLocalBounds().height) / 2;
			sprite.setPosition(centredSprite_x, centredSprite_y);
			if (EnableUILogging) {
				//Debugger::LogThis("Desenat tabla");
			}
		}
		else {

			sprite.setTexture(texture);
			sprite.setScale(0.5f, 0.5f);
		}
	}
	window->draw(sprite);
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
