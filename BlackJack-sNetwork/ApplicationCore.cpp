#include "ApplicationCore.h"

ApplicationCore::Application::Application() {
	current = ApplicationCore::Screen::Menu;
}

ApplicationCore::Application::~Application() {

}

ApplicationCore::Screen ApplicationCore::Application::GetCurrentScreen() {
	return current;
}

void ApplicationCore::Application::SetCurrentScreen(ApplicationCore::Screen currentScreen) {
	current = currentScreen;
	//draw stuff for current screen
}

