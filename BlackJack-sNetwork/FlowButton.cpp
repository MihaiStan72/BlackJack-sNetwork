#include "Flow.h"

Flow::Button::Button() {

};

Flow::Button::Button (UI::Position topLeftCorner, UI::Position bottomRightCorner, std::string name) {

}

Flow::Button::~Button() {

}

bool Flow::Button::IsPressed() {
	UI::Position mousePosition;
	if (topLeft.x < mousePosition.x && topLeft.y < mousePosition.y &&
		bottomRight.x > mousePosition.x && bottomRight.y > mousePosition.y) {
		return true;
	}
	return false;
}
