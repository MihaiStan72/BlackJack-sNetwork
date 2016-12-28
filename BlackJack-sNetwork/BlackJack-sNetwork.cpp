#include <SFML/Graphics.hpp>
#include "UI.h"
#include <iostream>

using namespace UI;

int main()
{
	while (WindowManager::GetReference().HasOpenWindows())
	{
		WindowManager::GetReference().CheckWindowForEvents(0);
	}
	std::cin.get();
	return 0;
}