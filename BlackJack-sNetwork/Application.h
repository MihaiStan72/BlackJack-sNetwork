#pragma once
namespace Application {
	 class Application {
	 public: 
		 enum State : int {
			Menu,
			Setup,
			Playing,
			Stopped,
			Exiting
		};
		 Application();
		 ~Application();
		 
	};
}
