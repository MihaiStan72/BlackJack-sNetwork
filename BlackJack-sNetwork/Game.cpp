#include "Game.h"
#include "UI.h" 
#include "ConcreteDrawableObjects.h"
#include <sstream>

using namespace UI;
using namespace ConcreteDrawableObjects;


Game::Game::Game() {

	gameState = State::Playing;
	ReadCards(cardsNumber);
	InitCardPos();
}

void Game::Game::InitCardPos() {

	playerCard_pos.x = 620; playerCard_pos.y = 370;
	dealerCard_pos.x = 620; dealerCard_pos.y = 15;
	sumPlayer = 0; sumDealer = 0;
	playerIndex = 0; dealerIndex = 0; number = 0;
}

void Game::Game::Start() {
	
	Loop();
	if (gameState == State::Restart) {

		while (gameState == State::Restart) {
			DeleteCards();
			InitCardPos();
			DrawAgent::GetReference().UpdateFrame();
			Loop();
		}
	}
	else if (gameState == State::Exiting) {
			
	}
}

void Game::Game::DeleteCards() {

	for (int index = 0; index < MAX_PLAYER_CARDS; index++) {
		
		DrawAgent::GetReference().Delete(playerCards.shownCards[index]);
		DrawAgent::GetReference().Delete(dealerCards.shownCards[index]);
	}
}

void Game::Game::ReadCards(int &cardsNumber) {

	std::ifstream fin("Resources/cards.txt");

	fin >> cardsNumber;
	for (int index = 0; index < cardsNumber; index++) {
		fin >> path;
		fin >> number;
		allCards.loadCards[index] = new Imagine();
		std::string sir = std::string(path);
		allCards.loadCards[index]->setPath(sir);
		allCards.values[index] = number;
	}
}

void Game::Game::GetRandomImg(Imagine *img, int &number){

	int randomNumber;
	randomNumber = rand() % cardsNumber;
	number = allCards.values[randomNumber];
	img->setPath(allCards.loadCards[randomNumber]->getPath());
}

void Game::Game::Create_playerCardsVector() {
	
	for (int index = 0; index < MAX_PLAYER_CARDS; index++){
		playerCards.shownCards[index] = new Imagine();
		GetRandomImg(playerCards.shownCards[index], number);
		playerCards.shownCards[index]->setPosition(UI::Position(playerCard_pos.x, playerCard_pos.y));
		playerCard_pos.x += 40; playerCard_pos.y += 20;
		playerCards.values[index] = number;
	}
}
void Game::Game::Create_dealerCardsVector() {

	for (int index = 0; index < MAX_PLAYER_CARDS; index++) {
		dealerCards.shownCards[index] = new Imagine();
		dealerCards.shownCards[index]->setPosition(UI::Position(dealerCard_pos.x, dealerCard_pos.y));
		dealerCard_pos.x += 40; dealerCard_pos.y += 20;
		GetRandomImg(dealerCards.shownCards[index], number);
		dealerCards.values[index] = number;
	}
}

void Game::Game::Draw_playerTwoCards() {

	sumPlayer += playerCards.values[playerIndex];
	DrawAgent::GetReference().Add(playerCards.shownCards[playerIndex++]);
	sumPlayer += playerCards.values[playerIndex];
	DrawAgent::GetReference().Add(playerCards.shownCards[playerIndex++]);
}

void Game::Game::Draw_dealerTwoCards() {

	Imagine *backCard = new Imagine();
	sumDealer += dealerCards.values[dealerIndex];
	DrawAgent::GetReference().Add(dealerCards.shownCards[dealerIndex++]);

	backCard->setPosition(UI::Position(660, 35));
	backCard->setPath("Resources/cards_PNG/back_card.png");
	DrawAgent::GetReference().Add(backCard);
}

void Game::Game::Loop() {

	bool ok = true;


	sf::Time delayTime = sf::seconds(1.5);
	sf::Time itsOver = sf::seconds(2);

	Text *playerWon = new Text();
	Text *dealerWon = new Text();

	WindowManager::WindowEvent event;
	Imagine *table = new Imagine();
	DrawAgent::GetReference().Add(table);

	//place_playerBets();
	Create_playerCardsVector();
	Create_dealerCardsVector();
	Draw_playerTwoCards();
	Draw_dealerTwoCards();

	playerWon->setPath("Player Won");
	playerWon->setPosition(UI::Position(86, 54));
	playerWon->SetTextDimm(60);

	dealerWon->setPath("Dealer Won");
	dealerWon->setPosition(UI::Position(86, 54));
	dealerWon->SetTextDimm(60);

	while (gameState != State::Exiting){
		
		DrawAgent::GetReference().UpdateFrame();

		event = WindowManager::GetReference().CheckWindowForEvents(0);
		if (event == WindowManager::WindowEvent::Close) {
			gameState = State::Exiting;
			break;
		}
		
	
		if (sumPlayer < BJ_CONDITION){

			if (event == WindowManager::WindowEvent::LeftClick) {
				sumPlayer += playerCards.values[playerIndex];
				DrawAgent::GetReference().Add(playerCards.shownCards[playerIndex++]);
			}
		}

		if (event == WindowManager::WindowEvent::RightClick || sumPlayer >= BJ_CONDITION){
			
			while (sumDealer < DEALER_CONDITION) {
				sumDealer += dealerCards.values[dealerIndex];
				DrawAgent::GetReference().Add(dealerCards.shownCards[dealerIndex++]);
			
			DrawAgent::GetReference().UpdateFrame();
			sf::sleep(delayTime);
			}

			if (sumDealer > BJ_CONDITION) {
				
				std::cout << "PlayerWins";
				DrawAgent::GetReference().Add(playerWon);
				gameState = State::Restart;
				bool over = true;
				break;

			}

			if (sumPlayer > BJ_CONDITION && sumDealer <= BJ_CONDITION) {
				
				std::cout << "DealerWins";
				DrawAgent::GetReference().Add(dealerWon);
				gameState = State::Restart;
				sf::sleep(itsOver);
				break;

			}

			if (sumPlayer == BJ_CONDITION) {

				std::cout << "Player Wins";
				DrawAgent::GetReference().Add(playerWon);
				gameState = State::Restart;
				sf::sleep(itsOver);
				break;
			}

			if (sumPlayer >= sumDealer) {

				std::cout << "Player Wins";
				DrawAgent::GetReference().Add(playerWon);
				gameState = State::Restart;
				sf::sleep(itsOver);
				break;
			}
			else
			{
				std::cout << "DealerWins";
				DrawAgent::GetReference().Add(dealerWon);
				gameState = State::Restart;
				sf::sleep(itsOver);
				break;
			}
		}
	}
}

Game::Game::~Game() {

}