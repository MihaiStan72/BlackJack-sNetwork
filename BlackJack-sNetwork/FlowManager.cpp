#include "Flow.h"
#include "ApplicationCore.h"
#include "UI.h"
#include "ConcreteDrawableObjects.h"

#define DEBUG 1

void Flow::FlowManager::Loop() {
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		if (DEBUG) {
			ApplicationCore::Application::GetReference()._game->Start();
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
	Flow::FlowManager::_buttonManager.DeleteAllButtons();
	
	if (screenTitle == "Instructions") {
		//draw instructions
	}
	if (screenTitle == "Game") {

	}
	//check title and draw screens accordingly
}

void Flow::FlowManager::CreateButton(std::string title, UI::Position topLeftCorner, UI::Position bottomRightCorner) {
	Flow::Button *flowButton = new Flow::Button(topLeftCorner, bottomRightCorner, title);
	FlowManager::_buttonManager.AddButton(flowButton);
	ConcreteDrawableObjects::Button *uiButton = new ConcreteDrawableObjects::Button();
	uiButton->setPosition(topLeftCorner);
//TODO change UI::button to have bottomright corner instead of width and height
}