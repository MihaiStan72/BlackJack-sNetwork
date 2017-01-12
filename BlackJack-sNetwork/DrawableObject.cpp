#include "UI.h"
#include <iostream>
using namespace UI;

DrawableObject::DrawableObject() {	
}

void DrawableObject::setPosition(Position position){

	topLeftPosition = position;
}

void DrawableObject::setPath(std::string string) {
	path = string;
}

DrawableObject::~DrawableObject() {
}
