#pragma once
#include "UI.h"
#include "Game.h"

namespace ApplicationCore {

	class Application {
	public: 
		 ~Application();

		 static Application& GetReference() {
			 static Application instance;
			 return instance;
		 }
		
		 Game::Game _game;
		 UI::Screen GetCurrentScreen();
		 void SetCurrentScreen(UI::Screen newScreen);
	private: 
		UI::Screen current;
		Application();
		Application(Application const&);//do not implement
		void operator=(Application const&);//do not implement
	};


}
