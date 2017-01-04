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

void DrawAgent::EraseAll() {
	referenceList.clear();
}

void DrawAgent::UpdateFrame() {
	
	sf::RenderWindow *window = WindowManager::GetReference().getWindow(0);
	window->clear();
	for each (DrawableObject* object in referenceList) {
		object->Draw();
	}
	window->display();
}
