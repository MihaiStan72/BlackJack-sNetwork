#include "Networking.h"

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
		
	};


	class Player {
	public:
		Player();
		Player(Networking::User user);
		virtual ~Player();

	};
}