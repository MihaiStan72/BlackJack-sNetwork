#include "Flow.h"

Flow::ButtonManager::ButtonManager() {

}

Flow::ButtonManager::~ButtonManager() {

}

void Flow::ButtonManager::AddButton(Flow::Button *button) {
	buttonList.push_back(button);
}

void Flow::ButtonManager::DeleteAllButtons() {
	for each (Flow::Button *button in buttonList) {
		//DeleteButton(button);
		UI::DrawAgent::GetReference().Delete(button->image);
	}
	buttonList.clear();
}

void Flow::ButtonManager::DeleteButton(Flow::Button *button) {
	buttonList.remove(button);
}

std::string Flow::ButtonManager::getPressedButton() {
	for each (Flow::Button *button in buttonList) {
		if (button->IsPressed()) {
			return button->name;
		}
	}
	return "";
}