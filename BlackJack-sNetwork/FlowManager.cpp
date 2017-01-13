#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

#define DebugGame 0
#define DebugScoreChart 0
#define DEBUGMENU 1
using namespace ConcreteDrawableObjects;
using namespace UI;

#define PlayTopPosition UI::Position(900, 200)
#define PlayBottomPosition UI::Position(1250, 315)

#define ScoresTopPosition UI::Position(900, 400)
#define ScoresBottomPosition UI::Position(1250, 515)

#define ExitTopPosition UI::Position(900, 600)
#define ExitBottomPosition UI::Position(1250, 715)

#define BackTopPosition UI::Position(900, 600)
#define BackBottomPosition UI::Position(1250, 715)


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
			else if (buttonName == "Exit") {
				ApplicationCore::Application::GetReference().SetCurrentScreen(Exit);
			}
			else if (buttonName == "Play") {
				ApplicationCore::Application::GetReference()._game->Start();
			}
			else if (buttonName == "Menu") {
				ApplicationCore::Application::GetReference().SetCurrentScreen(Menu);
				DrawScreen(Menu);
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
	Imagine *background = new Imagine();
	background->setPosition(UI::Position(-1, -1));
	DrawAgent::GetReference().Add(background);

	Flow::Button *playButton = CreateButton("Play", PlayTopPosition, PlayBottomPosition, "Resources/Photos/PlayButon.png");
	Flow::Button *scoreChartButton = CreateButton("ScoreChart", ScoresTopPosition, ScoresBottomPosition, "Resources/Photos/ScoresButton.png");
	Flow::Button *exitButton = CreateButton("Exit", ExitTopPosition, ExitBottomPosition, "Resources/Photos/ExitButton.png");
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
	Flow::Button *backButton = CreateButton("Menu", BackTopPosition, BackBottomPosition, "Resources/Photos/BackButton.png");
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