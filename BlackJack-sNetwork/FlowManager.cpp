#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

#define DebugGame 0
#define DebugScoreChart 0
#define DEBUGMENU 1
using namespace ConcreteDrawableObjects;
using namespace UI;


void Flow::FlowManager::Loop() {
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	DrawMenu();
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (checkResult == UI::WindowManager::WindowEvent::LeftClick) {
			std::string buttonName = _buttonManager.getPressedButton();
			if (buttonName == "ScoreChart") {
				Flow::FlowManager::DrawScreen(ScoreChart);
			}
			else if (buttonName == "Menu") {
				DrawScreen(Menu);
			}
			else if (buttonName == "Play") {
				ApplicationCore::Application::GetReference()._game->Start();
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



void Flow::FlowManager::DrawScreen(UI::Screen screen) {
	UI::DrawAgent::GetReference().EraseAll();
	_buttonManager.DeleteAllButtons();

	scoreChart.push_back("Bogdan P.           -999999");
	scoreChart.push_back("Andrei Timofte      100");
	scoreChart.push_back("Radu Stan           10");
	scoreChart.push_back("Mihai Stan          1000");

	if (screen == UI::Screen::ScoreChart) {
		DrawScoreChart(scoreChart);
	}
	if (screen == UI::Screen::Menu) {
		DrawMenu();
	}
	//check title and draw screens accordingly
}

void Flow::FlowManager::DrawMenu() {
	Flow::Button *playButton = CreateButton("Play", UI::Position(200, 200), UI::Position(400, 400), "Resources/Photos/buton.png");
	Flow::Button *scoreChartButton = CreateButton("ScoreChart", UI::Position(200, 600), UI::Position(400, 800), "Resources/Photos/buton.png");
	UI::DrawAgent::GetReference().UpdateFrame();
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

Flow::Button* Flow::FlowManager::CreateButton(std::string title, UI::Position topLeftCorner, UI::Position bottomRightCorner, std::string path) {
	Flow::Button *flowButton = new Flow::Button(topLeftCorner, bottomRightCorner, title);
	_buttonManager.AddButton(flowButton);
	ConcreteDrawableObjects::Imagine* image = new Imagine();
	image->setPosition(topLeftCorner);
	image->setPath(path);
	UI::DrawAgent::GetReference().Add(image);
	flowButton->image = image;
	return flowButton;
}

void Flow::FlowManager::DeleteButton(Flow::Button *button) {
	_buttonManager.DeleteButton(button);
	UI::DrawAgent::GetReference().Delete(button->image);
}