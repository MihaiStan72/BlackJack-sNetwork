#include <SFML/Graphics.hpp>
#include "UI.h"
#include <iostream>

using namespace UI;

int main()
{
	WindowManager::GetReference();
	std::cin.get();
	return 0;
}