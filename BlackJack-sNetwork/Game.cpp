#include "Game.h"
#include "UI.h" 
#include "ConcreteDrawableObjects.h"
#include <sstream>

using namespace UI;
using namespace ConcreteDrawableObjects;


Game::Game::Game() {
	gameState = State::Playing;
	x_Player = 620; y_Player = 370;
	x_Dealer = 610; y_Dealer = 15;
}

void Game::Game::Start() {
	Loop();
}

void Game::Game::readCards(int &cardsNumber) {

	std::ifstream fin("Resources/cards.txt");

	fin >> cardsNumber;
	for (int index = 0; index < cardsNumber; index++) {
		fin >> path;
		fin >> number;
		allCards.shownCards[index] = new Imagine();
		allCards.shownCards[index]->setPath(path);
		allCards.values[index] = number;
	}
}

void Game::Game::getRandomImg(Imagine *img, int &number){

	*img = new Imagine();
	int randomNumber;
	randomNumber = rand() % cardsNumber;

	number = allCards.values[randomNumber];
	img = allCards.shownCards[randomNumber];
}

void Game::Game::create_playerCardsVector() {
	
	for (int index = 0; index < MAX_PLAYER_CARDS; index++){
		playerCards.shownCards[index] = new Imagine();
		playerCards.shownCards[index]->setPosition(UI::Position(x_Player, y_Player));
		x_Player += 40; y_Player += 20;
		getRandomImg(playerCards.shownCards[index], number);
		playerCards.values[index] = number;
	}
}
void Game::Game::create_dealerCardsVector() {

	for (int index = 0; index < MAX_PLAYER_CARDS; index++) {
		dealerCards.shownCards[index] = new Imagine();
		dealerCards.shownCards[index]->setPosition(UI::Position(x_Dealer, y_Dealer));
		x_Dealer += 40; y_Dealer += 20;
		getRandomImg(dealerCards.shownCards[index], number);
		dealerCards.values[index] = number;
	}
}

void Game::Game::draw_playerTwoCards() {

	sumPlayer += playerCards.values[shownIndex];
	DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
	sumPlayer += playerCards.values[shownIndex];
	DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
}

void Game::Game::draw_dealerTwoCards() {

	Imagine *backCard = new Imagine();
	shownIndex = 0;


	sumDealer += dealerCards.values[shownIndex];
	DrawAgent::GetReference().Add(dealerCards.shownCards[shownIndex++]);

	backCard->setPosition(UI::Position(650, 35));
	backCard->setPath("Resources/cards_PNG/back_card.png");
	DrawAgent::GetReference().Add(backCard);
}

void Game::Game::Loop() {

	bool ok = true;
	sf::Time delayTime = sf::milliseconds(1000);
	WindowManager::WindowEvent event;
	Imagine *table = new Imagine();
	DrawAgent::GetReference().Add(table);
	
	//place_playerBets();
	readCards(cardsNumber);
	create_playerCardsVector();
	create_dealerCardsVector();
	draw_playerTwoCards();
	draw_dealerTwoCards();
	//create_dealerCardsVector();


	while (gameState != State::Exiting){
		
		DrawAgent::GetReference().UpdateFrame();

		event = WindowManager::GetReference().CheckWindowForEvents(0);
		if (event == WindowManager::WindowEvent::Close) {
			gameState = State::Exiting;
			break;
		}

		if (sumPlayer <= BJ_CONDITION){

			if (event == WindowManager::WindowEvent::LeftClick) {
				sumPlayer += playerCards.values[shownIndex];
				DrawAgent::GetReference().Add(playerCards.shownCards[shownIndex++]);
			}
		}

		if (event == WindowManager::WindowEvent::RightClick){
			shownIndex = 1;
			while (sumDealer < DEALER_CONDITION) {
				sumDealer += dealerCards.values[shownIndex];
				DrawAgent::GetReference().Add(dealerCards.shownCards[shownIndex++]);
				sf::sleep(delayTime);
			}
		}
	}
}

Game::Game::~Game() {

}