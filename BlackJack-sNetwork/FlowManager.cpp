#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

#define DEBUG 1

void Flow::FlowManager::Loop() {
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		if (DEBUG) {
			ApplicationCore::Application::GetReference()._game.Start();
			if (ApplicationCore::Application::GetReference()._game.gameState == Game::State::Exiting) {
				UI::Screen::Exit;
				break;
			}
		}
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (checkResult == UI::WindowManager::WindowEvent::Close) {
			ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Exit);
			break;
		}
		if (checkResult == UI::WindowManager::WindowEvent::LeftClick) {
			std::string buttonName = _buttonManager.getPressedButton();
			if (buttonName.empty() == false) {
				DrawScreen(buttonName);
			}
		}
	}
}

Flow::FlowManager::FlowManager() {
	Loop();
}

Flow::FlowManager::~FlowManager() {

}

void Flow::FlowManager::DrawScreen(std::string screenTitle) {
	UI::DrawAgent::GetReference().EraseAll();
	//check title and draw screens accordingly
}