#pragma once
#include "UI.h"
#include "ConcreteDrawableObjects.h"

namespace Flow {

	class Button {
	public:

		Button();
		Button(UI::Position topLeftCorner, UI::Position bottomRightCorner, std::string name);
		virtual ~Button();

		std::string name;
		bool IsPressed();
		ConcreteDrawableObjects::Button *UIButton;
	private:
		UI::Position topLeft, bottomRight;
	};

	class ButtonManager {
	public:
		ButtonManager();
		virtual ~ButtonManager();

		void ButtonManager::AddButton(Flow::Button *button);

		void DeleteButton(Flow::Button *);
		void DeleteAllButtons();
		std::string getPressedButton();
	private:
		std::list<Flow::Button*> buttonList;
	};

	class FlowManager {
	public:
		FlowManager();
		virtual ~FlowManager();

		void Loop();
		void CreateButton(std::string title, UI::Position topLeftCorner, UI::Position bottomRightCorner);
		void DeleteButton(Flow::Button *);
	private:
		Flow::ButtonManager _buttonManager;
		ConcreteDrawableObjects::Button UIButton;
		void SetScreenForButton(std::string buttonName);
		void DrawScreen(std::string screenTitle);
	};
}