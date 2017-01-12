#include "UI.h"
#include <iostream>
using namespace UI;

DrawableObject::DrawableObject() {	
	topLeftPosition = Position(0, 0);
}

void DrawableObject::setPosition(Position position){
	topLeftPosition.x = position.x;
	topLeftPosition.y = position.y;
}

void DrawableObject::setPath(std::string string) {
	path = string;
}

DrawableObject::~DrawableObject() {
}
