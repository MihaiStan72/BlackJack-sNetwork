#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"

#define DebugGame 0
#define DebugScoreChart 0
#define DEBUGMENU 1

void Flow::FlowManager::Loop() {
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	DrawMenu();
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (checkResult == UI::WindowManager::WindowEvent::LeftClick) {
			std::string buttonName = _buttonManager.getPressedButton();
			if (buttonName == "ScoreChart") {
				DrawScreen(ScoreChart);
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
	if (screen == UI::Screen::ScoreChart) {
		DrawScoreChart();
	}
	if (screen == UI::Screen::Menu) {
		DrawMenu();
	}
	//check title and draw screens accordingly
}

void Flow::FlowManager::DrawScoreChart() {
	std::cout << "DrawChart";
}

void Flow::FlowManager::DrawMenu() {
	Flow::Button *playButton = CreateButton("Play", UI::Position(200, 200), UI::Position(400, 400), "Resources/Photos/buton.png");
	Flow::Button *scoreChartButton = CreateButton("ScoreChart", UI::Position(200, 600), UI::Position(400, 800), "Resources/Photos/buton.png");
	UI::DrawAgent::GetReference().UpdateFrame();
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