#include "Game.h"
#include "UI.h" 
#include "ConcreteDrawableObjects.h"

using namespace UI;
using namespace ConcreteDrawableObjects;


Game::Game::Game() {
	gameState = State::Playing;
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

void  Game::Game::getRandomPath(char path[MAX_CARDS], int &number) {

	readCards(cardsNumber);

	srand(time(NULL));
	int randomNumber;
	randomNumber = rand() % cardsNumber;

	number = cards.value[randomNumber];
	int index;
	for (index = 0; cards.Matrix[randomNumber][index]; index++) {
		path[index] = cards.Matrix[randomNumber][index];
	}
	path[index] = '\0';
}

void Game::Game::create_playerCardsVector() {

	for (int index = 0; index < MAX_PLAYER_CARDS; index++){
		playerCards.shownCards[index] = new Imagine();
		playerCards.shownCards[index]->setPosition(UI::Position(100, 100));///////*****************
		getRandomPath(path, number);
		playerCards.shownCards[index]->setPath(path);
		playerCards.values[index] = number;
	}
}

void Game::Game::draw_playerTwoCards() {

	DrawAgent::GetReference().Add(playerCards.shownCards[0]);
	DrawAgent::GetReference().Add(playerCards.shownCards[1]);
}

void Game::Game::Loop() {

	WindowManager::WindowEvent event;
	Imagine *table = new Imagine();
	DrawAgent::GetReference().Add(table);

	//place_playerBets();
	create_playerCardsVector();
	draw_playerTwoCards();
	//create_dealerCardsVector();

	while (gameState != State::Exiting){
		
		event = WindowManager::GetReference().CheckWindowForEvents(0);
		if (event == WindowManager::WindowEvent::Close) {
			gameState = State::Exiting;
			break;
		}
		DrawAgent::GetReference().UpdateFrame();
	}
}

Game::Game::~Game() {

}