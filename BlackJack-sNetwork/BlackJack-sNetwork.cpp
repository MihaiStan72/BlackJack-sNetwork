#include "UI.h"
#include "ApplicationCore.h"
#include "debug.h"

int main()
{	
	ApplicationCore::Application::GetReference().SetCurrentScreen(ApplicationCore::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != ApplicationCore::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (checkResult == UI::WindowManager::WindowEvent::Close) {
			ApplicationCore::Application::GetReference().SetCurrentScreen(ApplicationCore::Screen::Exit);
		}
	}
	return 0;
}