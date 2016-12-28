#include "UI.h"
#include <iostream>
using namespace UI;

DrawableObject::DrawableObject() {	
}

void DrawableObject::setPosition(int x, int y){

	screenPosition.Position::Position(x, y);
}

DrawableObject::~DrawableObject() {
}
