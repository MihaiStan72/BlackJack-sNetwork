#include "UI.h"
#include <iostream>
using namespace UI;

DrawableObject::DrawableObject() {	
}

void DrawableObject::setPosition(Position position){

<<<<<<< HEAD
	topLeftPosition = position;
=======
	screenPosition = Position(position);
>>>>>>> origin/master
}

void DrawableObject::setPath(std::string string) {
	path = string;
}

DrawableObject::~DrawableObject() {
}
