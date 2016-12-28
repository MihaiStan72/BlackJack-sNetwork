#include <SFML/Graphics.hpp>
#include "UI.h"
#include <windows.h>
#include <iostream>
#include "ConcreteDrawableObjects.h"

using namespace UI;
using namespace ConcreteDrawableObjects;

int main()
{

	/*wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH - 1);
	std::wcout << buffer;
	std::cin.get();*/

	Imagine *table = new Imagine();
    DrawAgent::GetReference().Add(table);
	

	while (WindowManager::GetReference().HasOpenWindows())
	{	
		DrawAgent::GetReference().UpdateFrame();
		WindowManager::GetReference().CheckWindowForEvents(0);
	}
	std::cin.get();
	return 0;
}