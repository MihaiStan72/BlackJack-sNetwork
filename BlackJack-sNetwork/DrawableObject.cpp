#include "UI.h"
#include <iostream>
using namespace UI;

DrawableObject::DrawableObject() {	
}

void DrawableObject::setPosition(int x, int y){

	screenPosition.Position::Position(x, y);
}

void DrawableObject::setPath(std::string string) {
	path = string;
}

DrawableObject::~DrawableObject() {
}
