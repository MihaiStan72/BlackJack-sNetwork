#include "Flow.h"

Flow::Button::Button() {

};

Flow::Button::Button (UI::Position topLeftCorner, UI::Position bottomRightCorner, std::string name) {
	topLeft.x = topLeftCorner.x;
	topLeft.y = topLeftCorner.y;
	bottomRight.x = bottomRightCorner.x;
	bottomRight.y = bottomRightCorner.y;
	this->name = name;
}

Flow::Button::~Button() {

}

bool Flow::Button::IsPressed() {
	sf::Window *window = UI::WindowManager::GetReference().getWindow(0);
	sf::Vector2i mouseVector = sf::Mouse::getPosition(*window);
	UI::Position mousePosition;
	mousePosition.x = mouseVector.x;
	mousePosition.y = mouseVector.y;
	if (topLeft.x < mousePosition.x && topLeft.y < mousePosition.y &&
		bottomRight.x > mousePosition.x && bottomRight.y > mousePosition.y) {
		return true;
	}
	return false;
}
