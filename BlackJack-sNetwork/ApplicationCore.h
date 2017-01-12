#pragma once
#include "UI.h"

namespace ApplicationCore {

	class Application {
	public: 
		 ~Application();	
		 UI::DrawManager drawManager;

		 static Application& GetReference() {
			 static Application instance;
			 return instance;
		 }

		 UI::Screen GetCurrentScreen();
		 void SetCurrentScreen(UI::Screen newScreen);
	private: 
		UI::Screen current;
		Application();
		Application(Application const&);//do not implement
		void operator=(Application const&);//do not implement
	};


}
