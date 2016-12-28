#include <SFML/Graphics.hpp>
#include "UI.h"
#include <iostream>
#include "ConcreteDrawableObjects.h"

using namespace UI;
using namespace ConcreteDrawableObjects;

int main()
{
	Imagine *imagine = new Imagine();
	//DrawAgent::GetReference().Add(imagine);
	//DrawAgent::GetReference().UpdateFrame();
	std::cin.get();

	return 0;
}