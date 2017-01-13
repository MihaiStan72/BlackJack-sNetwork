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
		void InitCardPos();
		void ReadCards(int &cardsNumber);
		void DeleteCards();
		void GetRandomImg(Imagine *img, int &number);
		void Draw_playerTwoCards();
		void Draw_dealerTwoCards();
		void Create_playerCardsVector();
		void Create_dealerCardsVector();
		Position playerCard_pos, dealerCard_pos;

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

} 