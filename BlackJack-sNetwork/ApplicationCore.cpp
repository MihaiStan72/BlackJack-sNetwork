#include "ApplicationCore.h"

ApplicationCore::Application::Application() {
	current = UI::Screen::Menu;
}

ApplicationCore::Application::~Application() {

}

UI::Screen ApplicationCore::Application::GetCurrentScreen() {
	return current;
}

void ApplicationCore::Application::SetCurrentScreen(UI::Screen currentScreen) {
	current = currentScreen;

}

