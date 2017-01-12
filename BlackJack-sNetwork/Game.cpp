#include "Game.h"
#include "UI.h" 
#include "ConcreteDrawableObjects.h"

using namespace UI;
using namespace ConcreteDrawableObjects;


Game::Game::Game() {
	gameState = State::Playing;
}

void Game::Game::Start() {
	Loop();
}

void Game::Game::Loop() {

	WindowManager::WindowEvent event;
	Imagine *table = new Imagine();
	DrawAgent::GetReference().Add(table);

	 
	
	//placePlayerBets();

	while (gameState != State::Exiting){
		
		event = WindowManager::GetReference().CheckWindowForEvents(0);
		if (event == WindowManager::WindowEvent::Close) {
			gameState = State::Exiting;
			break;
		}
		DrawAgent::GetReference().UpdateFrame();
	}
}

Game::Game::~Game() {

}