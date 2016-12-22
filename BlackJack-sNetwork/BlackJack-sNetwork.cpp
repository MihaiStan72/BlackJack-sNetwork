#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Imagine.h"
#include <iostream>

using namespace UI;

int main()
{
	Imagine* image = new Imagine();
	(DrawAgent::GetReference()).Add(image);
	DrawAgent::GetReference().UpdateFrame();
	std::cin.get();
	return 0;
}