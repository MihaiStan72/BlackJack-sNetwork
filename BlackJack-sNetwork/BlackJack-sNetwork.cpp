#include "UI.h"
#include "ApplicationCore.h"
#include "debug.h"

int main()
{	
	ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Menu);
	UI::WindowManager::WindowEvent checkResult = UI::WindowManager::WindowEvent::NoEvent;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != UI::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (checkResult == UI::WindowManager::WindowEvent::Close) {
			ApplicationCore::Application::GetReference().SetCurrentScreen(UI::Screen::Exit);
		}
	}
	return 0;
}