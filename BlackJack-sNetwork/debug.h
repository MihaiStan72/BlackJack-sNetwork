#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#define EnableUILogging 1

namespace Debugger {
	void DrawFPS() {
			sf::Clock clock;
			static double lastTime = 0;
			double currentTime = clock.restart().asSeconds();
			double fps = 1.f / (currentTime - lastTime);
			lastTime = currentTime;
			std::cout << fps << "\n";
	}

	void LogThis(std::string message) {
		std::cout << message << "\n";
	}
}