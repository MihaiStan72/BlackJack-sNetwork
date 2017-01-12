#include "Game.h"
#include "UI.h" 
#include "ConcreteDrawableObjects.h"
#include <sstream>

using namespace UI;
using namespace ConcreteDrawableObjects;


Game::Game::Game() {
	gameState = State::Playing;
	x_Player = 620; y_Player = 370;
}

void Game::Game::Start() {
	Loop();
}

void Game::Game::readCards(int &cardsNumber) {

	std::ifstream fin("Resources/cards.txt");

	fin >> cardsNumber;
	for (int index = 0; index < cardsNumber; index++) {
		fin >> cards.Matrix[index];
		fin >> cards.value[index];
	}
}

void Game::Game::getRandomPath(char path[MAX_CARDS], int &number){

	srand(time(NULL));
	int randomNumber;
	randomNumber = rand() % cardsNumber;

	number = cards.value[randomNumber];
	int index;
	for (index = 0; cards.Matrix[randomNumber][index]; index++) {
		path[index] = cards.Matrix[randomNumber][index];
	}
	std::cout << number<< '\n';
	path[index] = '\0';
}

void Game::Game::create_playerCardsVector() {
	
	for (int index = 0; index < MAX_PLAYER_CARDS; index++){
		playerCards.shownCards[index] = new Imagine();
		playerCards.shownCards[index]->setPosition(UI::Position(x_Player, y_Player));
		x_Player += 40; y_Player += 20;
		getRandomPath(path, number);
		std::cout << path << '\n';
		std::cout << number <<  '\n';
		playerCards.shownCards[index]->setPath(path);
		playerCards.values[index] = number;
	}
}

void Game::Game::draw_playerTwoCards() {

	DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
	DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
}

void Game::Game::Loop() {

	WindowManager::WindowEvent event;
	Imagine *table = new Imagine();
	DrawAgent::GetReference().Add(table);

	//place_playerBets();
	readCards(cardsNumber);
	create_playerCardsVector();
	draw_playerTwoCards();
	//create_dealerCardsVector();


	while (gameState != State::Exiting){
		
		event = WindowManager::GetReference().CheckWindowForEvents(0);
		if (event == WindowManager::WindowEvent::Close) {
			gameState = State::Exiting;
			break;
		}

		//if (sumPlayer < BJ_CONDITION && event == WindowManager::WindowEvent::LeftClick) {

			//DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
		//}

		DrawAgent::GetReference().UpdateFrame();
	}
}

Game::Game::~Game() {

}