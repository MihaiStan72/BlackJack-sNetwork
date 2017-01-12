#include "Flow.h"

Flow::ButtonManager::ButtonManager() {

}

Flow::ButtonManager::~ButtonManager() {

}

std::string Flow::ButtonManager::getPressedButton() {
	for each (Flow::Button *button in buttonList) {
		if (button->IsPressed()) {
			return button->name;
		}
	}
	return NULL;
}