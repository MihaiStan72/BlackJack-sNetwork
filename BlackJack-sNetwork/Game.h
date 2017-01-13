#include "Networking.h"
#include "UI.h" 
#include <fstream>
#include <iostream>
#include "ConcreteDrawableObjects.h"
#define MAX_CARDS 52
#define MAX_PLAYER_CARDS 11
#define BJ_CONDITION 21
#define DEALER_CONDITION 17

using namespace UI;
using namespace ConcreteDrawableObjects;

namespace Game {

	enum State : int {
		Playing,
		Exiting,
		Restart

	};


	class Game {
	public:
		Game();
		virtual ~Game();
		void Start();
		State gameState;
	private:
		void Loop();
		void readCards(int &cardsNumber);
		void deleteCards();
		void getRandomImg(Imagine *img, int &number);
		void draw_playerTwoCards();
		void draw_dealerTwoCards();
		void create_playerCardsVector();
		void create_dealerCardsVector();

		struct {
			Imagine *loadCards[MAX_CARDS];
			int values[MAX_CARDS];
		}allCards;

		struct{
			Imagine *shownCards[MAX_PLAYER_CARDS];
			int values[MAX_PLAYER_CARDS];
		}playerCards, dealerCards;
		char path[MAX_CARDS];
		int cardsNumber=0, sumPlayer=0, sumDealer=0, playerIndex=0, dealerIndex=0, number=0;
		float x_Player, y_Player, x_Dealer, y_Dealer;
	};

	class Player {
	public:
		Player();
		//virtual Player(Networking::User user);
		virtual ~Player();
	private:
		Position playerCardsPos;
	};

	class SetOfCards {
	public:
		SetOfCards();
		void Fill();
	private:

	};
}