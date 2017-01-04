#include "Networking.h"

namespace Game {

	class Game {
	public:
		Game();
		void Start();

		static Game Singleton();
	private:

	};


	class Player {
	public:
		Player();
		Player(Networking::User user);
		virtual ~Player();

	};
}