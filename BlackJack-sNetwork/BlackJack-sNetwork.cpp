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
	Imagine *cardOne_Player = new Imagine();
	Imagine *cardTwo_Player = new Imagine();
	Imagine *cardOne_Dealer = new Imagine();
	Imagine *cardTwo_Dealer = new Imagine();


	cardOne_Player->setPosition(620, 370);
	cardTwo_Player->setPosition(660, 390);
	cardOne_Dealer->setPosition(610, 15);
	cardTwo_Dealer->setPosition(650, 35);
	cardOne_Player->setPath("Resources/cards_PNG/10_of_clubs.png");
	cardTwo_Player->setPath("Resources/cards_PNG/10_of_hearts.png");
	cardOne_Dealer ->setPath("Resources/cards_PNG/10_of_clubs.png");
	cardTwo_Dealer ->setPath("Resources/cards_PNG/back_card.png");

    DrawAgent::GetReference().Add(table); 
	DrawAgent::GetReference().Add(cardOne_Player);
	DrawAgent::GetReference().Add(cardTwo_Player);
	DrawAgent::GetReference().Add(cardOne_Dealer);
	DrawAgent::GetReference().Add(cardTwo_Dealer);

	while (WindowManager::GetReference().HasOpenWindows())
	{	
		DrawAgent::GetReference().UpdateFrame();
		WindowManager::GetReference().CheckWindowForEvents(0);
	}
	std::cin.get();
	return 0;
}