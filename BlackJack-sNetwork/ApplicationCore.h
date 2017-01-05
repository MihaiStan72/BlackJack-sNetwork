#pragma once

namespace ApplicationCore {
	enum Screen : int {
		Menu,
		SinglePlayer,
		Multiplayer,
		Instructions,
		Exit
	};

	class Application {
	public: 
		 ~Application();	


		 static Application& GetReference() {
			 static Application instance;
			 return instance;
		 }

		 Screen GetCurrentScreen();
		 void SetCurrentScreen(Screen newScreen); 
	private: 
		Screen current;
		Application();
		Application(Application const&);//do not implement
		void operator=(Application const&);//do not implement
	};


}
