#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

#define DebugGame 1
#define DebugScoreChart 0

void Flow::FlowManager::Loop() {
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		if (DebugGame) {
			ApplicationCore::Application::GetReference()._game->Start();
			if (ApplicationCore::Application::GetReference()._game->gameState == Game::State::Exiting) {
				UI::Screen::Exit;
				break;
			}
		}
		if (DebugScoreChart) {
			ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::ScoreChart);
			DrawScreen("ScoreChart");
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

void Flow::FlowManager::SetScreenForButton(std::string buttonName) {
	if (buttonName == "Play") {
		ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::SinglePlayer);
		//tbi;
	}
}


void Flow::FlowManager::DrawScreen(std::string screenTitle) {
	UI::DrawAgent::GetReference().EraseAll();
	_buttonManager.DeleteAllButtons();
	if (screenTitle == "ScoreChart") {
		DrawScoreChart();
	}
	//check title and draw screens accordingly
}

void Flow::FlowManager::DrawScoreChart() {
	//std::cout << "DrawChart";
}

void Flow::FlowManager::CreateButton(std::string title, UI::Position topLeftCorner, UI::Position bottomRightCorner) {
	Flow::Button *flowButton = new Flow::Button(topLeftCorner, bottomRightCorner, title);
	_buttonManager.AddButton(flowButton);
	ConcreteDrawableObjects::Button *UIButton = new ConcreteDrawableObjects::Button();
	UIButton->setPosition(topLeftCorner);
	UIButton->SetWidthAndHeight(topLeftCorner.x - bottomRightCorner.x, topLeftCorner.y - bottomRightCorner.y);
	flowButton->UIButton = UIButton;
}

void Flow::FlowManager::DeleteButton(Flow::Button *button) {
	_buttonManager.DeleteButton(button);
	UI::DrawAgent::GetReference().Delete(button->UIButton);
}