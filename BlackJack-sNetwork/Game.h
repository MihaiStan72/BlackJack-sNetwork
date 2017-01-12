#include "Networking.h"
#include "UI.h" 
#include <fstream>
#include "ConcreteDrawableObjects.h"
#include <sstream>
#define MAX_CARDS 60
#define MAX_PLAYER_CARDS 11

using namespace UI;
using namespace ConcreteDrawableObjects;

namespace Game {

	enum State : int {
		Playing,
		Exiting
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
		void getRandomPath(char path[MAX_CARDS], int &number);
		void draw_playerTwoCards();
		void create_playerCardsVector();
		struct {
			char Matrix[MAX_CARDS][MAX_CARDS];
			int value[MAX_CARDS];
		}cards;

		struct{
			Imagine *shownCards[MAX_PLAYER_CARDS]	;
			int values[MAX_PLAYER_CARDS];
		}playerCards, dealerCards;
		char path[MAX_CARDS];
		int number=0, cardsNumber=0;
	};

	class Player {
	public:
		Player();
		Player(Networking::User user);
		virtual ~Player();

	};
}