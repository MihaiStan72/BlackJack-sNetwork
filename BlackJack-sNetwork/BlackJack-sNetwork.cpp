#include "UI.h"
#include "ApplicationCore.h"
#include "debug.h"

int main()
{	
	ApplicationCore::Application::GetReference().SetCurrentScreen(ApplicationCore::Screen::Menu);
	int checkResult = 0;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != ApplicationCore::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (!checkResult) {
			ApplicationCore::Application::GetReference().SetCurrentScreen(ApplicationCore::Screen::Exit);
		}
	}
	std::cin.get();
	return 0;
}