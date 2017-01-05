#include "ApplicationCore.h"
#include "UI.h"


int main()
{	
	ApplicationCore::Application::GetReference().SetCurrentScreen(ApplicationCore::Screen::Menu);
	int checkResult = 0;
	while (ApplicationCore::Application::GetReference().GetCurrentScreen() != ApplicationCore::Screen::Exit) {
		checkResult = UI::WindowManager::GetReference().CheckWindowForEvents(0);
		if (!checkResult) {

		}
	}
	return 0;
}