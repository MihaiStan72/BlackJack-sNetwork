#pragma once
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace UI {
		
	class Position {
	public:
		Position();
		Position(float horizontalCoordinate, float verticalCoordinate);
		virtual ~Position();
		Position(Position const& position);
		int x, y;
	};

	enum Screen : int {
		Menu,
		SinglePlayer,
		Multiplayer,
		Instructions,
		Exit
	};

	class DrawableObject {
	public:
		DrawableObject();
		virtual ~DrawableObject();

		virtual void Draw() = 0;

		void setPosition(Position position);
		void setPath(std::string);
		
	protected:
		Position topLeftPosition, bottomRightPosition;
		std::string path;
		
	};

	class DrawAgent {	
	public:
		
		~DrawAgent();

		static DrawAgent& GetReference() {
			static DrawAgent instance;
			return instance;
		}

		void UpdateFrame();

		void Add(DrawableObject *object);
		void Delete(DrawableObject *object);
		void EraseAll();
	private:
		DrawAgent();
		DrawAgent(DrawAgent const&);//do not implement
		void operator=(DrawAgent const&);//do not implement
		std::list<DrawableObject*> referenceList;
	};

	class WindowManager {
	public:

		enum WindowEvent : int {
			Close,
			LeftClick,
			RightClick,
			MiddleClick,
			NoEvent
		};

		static WindowManager& GetReference() {
			static WindowManager instance;
			return instance;
		}

		sf::RenderWindow* getWindow(int index);
		
		void CreateWindow();
		void CloseWindow(int index);
		virtual ~WindowManager();

		WindowEvent CheckWindowForEvents(int index);
		bool HasOpenWindows();

	private:
		std::vector<sf::RenderWindow*>windowVector;	

		WindowManager();
		WindowManager(WindowManager const&);//do not implement
		void operator=(WindowManager const&);//do not implement
		bool isButtonPressed();
		sf::Vector2i mousePosition;
	};
}