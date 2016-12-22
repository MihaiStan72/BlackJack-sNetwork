#include "UI.h"

using namespace UI;

DrawAgent::DrawAgent(){
	
}

DrawAgent::~DrawAgent() {
	
}

void DrawAgent::Add(DrawableObject* object) {
	referenceList.push_back(object);
}

void DrawAgent::Delete(DrawableObject* object) {
	referenceList.remove(object);
}

void DrawAgent::UpdateFrame() {
	for each (DrawableObject* object in referenceList) {
		object->Draw();
	}
}
