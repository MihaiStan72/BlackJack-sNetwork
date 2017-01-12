#include "Networking.h"

namespace Game {

	class Game {
	public:
		Game();
		virtual ~Game();
		void Start();
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