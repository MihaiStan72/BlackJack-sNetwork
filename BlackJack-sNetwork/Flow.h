#pragma once
#include "UI.h"

namespace Flow {

	class Button {
	public:

		Button();
		Button(UI::Position topLeftCorner, UI::Position bottomRightCorner, std::string name);
		virtual ~Button();

		std::string name;
		bool IsPressed();
	private:
		UI::Position topLeft, bottomRight;
	};

	class ButtonManager {
	public:
		ButtonManager();
		virtual ~ButtonManager();

		std::string getPressedButton();
	private:
		std::list<Flow::Button*> buttonList;
	};

	class FlowManager {
	public:
		FlowManager();
		virtual ~FlowManager();


		void Loop();

	private:
		Flow::ButtonManager _buttonManager;
		void DrawScreen(std::string screenTitle);
	};
}