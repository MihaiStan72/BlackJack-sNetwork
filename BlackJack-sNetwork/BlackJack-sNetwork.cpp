#include <SFML/Graphics.hpp>
#include "UI.h"
#include <windows.h>
#include <iostream>
#include "ConcreteDrawableObjects.h"
#include <sstream>
#include <fstream>
#include "debug.h"
#define MAX_CARDS 60

using namespace UI;
using namespace ConcreteDrawableObjects;

struct{
	char Matrix[MAX_CARDS][MAX_CARDS];
	int value[MAX_CARDS];
}cards;
bool uniqueCard[MAX_CARDS];

void readPaths(int &cardsNumber) {
	
	std::ifstream fin ("Resources/cards.txt");

	fin >> cardsNumber;
	for (int index = 0; index < cardsNumber; index++){
		fin >> cards.Matrix[index];
		fin >> cards.value[index];
	}
}

void getRandomPath(char path[MAX_CARDS], int &number){
	int cardsNumber=0;
	readPaths(cardsNumber);
	
	srand(time(NULL));
	int randomNumber;
	randomNumber = rand() % cardsNumber;

	if (uniqueCard[randomNumber] == true) {
		while (uniqueCard[randomNumber] == true) {
			randomNumber = rand() % cardsNumber;
		}
	}
	uniqueCard[randomNumber] = true;
	number=cards.value[randomNumber];
	int index;
	for (index = 0; cards.Matrix[randomNumber][index]; index++) {
		path[index]= cards.Matrix[randomNumber][index];
	}
	path[index] = '\0';
}

int sumPlayer = 0, sumDealer = 0, number;
char path[MAX_CARDS];

void draw_initialCards(){

	Imagine *table = new Imagine();
	Imagine *cardOne_Player = new Imagine();
	Imagine *cardTwo_Player = new Imagine();
	Imagine *cardOne_Dealer = new Imagine();
	Imagine *cardTwo_Dealer = new Imagine();
	Text *cardsSum_Player = new Text();
	Text *cardsSum_Dealer = new Text();
	Button *button = new Button();
	

	cardOne_Player->setPosition(620, 370);
	cardTwo_Player->setPosition(660, 390);
	cardOne_Dealer->setPosition(610, 15);
	cardTwo_Dealer->setPosition(650, 35);
	cardsSum_Player->setPosition(550, 405);
	button->setPosition(250, 350);
	button->setScaleSize(0.25, 0.25);

	getRandomPath(path, number);
	cardOne_Player->setPath(path);
	sumPlayer += number;

	getRandomPath(path, number);
	cardTwo_Player->setPath(path);
	sumPlayer += number;

	getRandomPath(path, number);
	cardOne_Dealer->setPath(path);
	sumDealer += number;
	cardTwo_Dealer->setPath("Resources/cards_PNG/back_card.png");
	//cardsSum_Player->setPath("adadsa");

	DrawAgent::GetReference().Add(table);
	DrawAgent::GetReference().Add(cardOne_Player);
	DrawAgent::GetReference().Add(cardTwo_Player);
	DrawAgent::GetReference().Add(cardOne_Dealer);
	DrawAgent::GetReference().Add(cardTwo_Dealer);
	DrawAgent::GetReference().Add(cardsSum_Player);
	DrawAgent::GetReference().Add(cardsSum_Dealer);
	DrawAgent::GetReference().Add(button);
}

void draw_newPlayerCard(){
	
	Imagine *newCard = new Imagine();
	newCard->setPosition(700, 410);
	getRandomPath(path, number);
	newCard->setPath(path);
	sumPlayer += number;
	DrawAgent::GetReference().Add(newCard);
}

void draw_newDealerCard(){

	Imagine *newCard = new Imagine();
	newCard->setPosition(650, 35);
	getRandomPath(path, number);
	newCard->setPath(path);
	sumDealer += number;
	DrawAgent::GetReference().Add(newCard);
}

int main()
{	
	draw_initialCards();
	while (WindowManager::GetReference().HasOpenWindows()){	
		int result = WindowManager::GetReference().CheckWindowForEvents(0);

		if (result == 1) {
			draw_newPlayerCard();
		}

		if (result == 2) {
			draw_newDealerCard();
		}
	
		DrawAgent::GetReference().UpdateFrame();	
	}
	std::cin.get();
	return 0;
}