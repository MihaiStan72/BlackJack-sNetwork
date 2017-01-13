#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

using namespace ConcreteDrawableObjects;
using namespace UI;

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

	scoreChart.push_back("Bogdan P.           -999999");
	scoreChart.push_back("Andrei Timofte      100");
	scoreChart.push_back("Radu Stan           10");
	scoreChart.push_back("Mihai Stan          1000");

	if (screenTitle == "ScoreChart") {
		DrawScoreChart(scoreChart);
	}
	//check title and draw screens accordingly
}

void Flow::FlowManager::DrawScoreChart(std::vector<std::string> scoreChart) {

	namePos.x = 746; namePos.y = 263;
	Imagine *background = new Imagine();
	Text *score = new Text();
	Text *vectorName[10];
	background->setPosition(UI::Position(-1, -1));
	
	score->setPath("Score Chart");
	score->setPosition(UI::Position(740, 35));
	score->SetTextDimm(60);
		
	DrawAgent::GetReference().Add(background);
	DrawAgent::GetReference().Add(score);
	for (int index = 0; index < scoreChart.size(); index++) {
		
		vectorName[index] = new Text();
		vectorName[index]->setPath(scoreChart[index]);
		vectorName[index]->SetTextDimm(30);
		vectorName[index]->setPosition(UI::Position(namePos.x, namePos.y));
		namePos.y += 30;
		DrawAgent::GetReference().Add(vectorName[index]);
	}
	DrawAgent::GetReference().UpdateFrame();
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