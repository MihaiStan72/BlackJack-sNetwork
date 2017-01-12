#include "Flow.h"

Flow::ButtonManager::ButtonManager() {

}

Flow::ButtonManager::~ButtonManager() {

}

void Flow::ButtonManager::AddButton(Flow::Button *button) {
	buttonList.push_back(button);
}

void Flow::ButtonManager::DeleteAllButtons() {
	buttonList.clear();
}

std::string Flow::ButtonManager::getPressedButton() {
	for each (Flow::Button *button in buttonList) {
		if (button->IsPressed()) {
			return button->name;
		}
	}
	return "";
}