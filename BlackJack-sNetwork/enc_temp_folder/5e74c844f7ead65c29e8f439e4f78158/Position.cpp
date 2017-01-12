#include "UI.h"

using namespace UI;

Position::Position() {
}

Position::Position(float horizontalCoordinate, float verticalCoordinate){
	
	x = horizontalCoordinate;
	y = verticalCoordinate;
}

Position::~Position(){
}

Position::Position(Position const& position) {
	x = position.x;
	y = position.y;
}
