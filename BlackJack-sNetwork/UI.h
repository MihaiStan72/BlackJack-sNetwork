#pragma once
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace UI {
		
	class Position {
	public:
		Position();
		Position(float horizontalCoordinate, float verticalCoordinate);
		~Position();
		 int x, y;
	};

	class DrawableObject {
	public:
		DrawableObject();
		virtual ~DrawableObject();

		virtual void Draw() = 0;
		bool operator==(DrawableObject const&) {
			return true;
		}
		void setPosition(int, int);
		void setPath(std::string);
		
	protected:
		Position screenPosition;
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
		static WindowManager& GetReference() {
			static WindowManager instance;
			return instance;
		}

		sf::RenderWindow* getWindow(int index);
		
		void CreateWindow();
		void CloseWindow(int index);
		virtual ~WindowManager();

		int CheckWindowForEvents(int index);
		bool HasOpenWindows();
	private:
		std::vector<sf::RenderWindow*>windowVector;	

		WindowManager();
		WindowManager(WindowManager const&);//do not implement
		void operator=(WindowManager const&);//do not implement
	};	

	class DrawManager {
	public:
		DrawManager();
		virtual ~DrawManager();

		void DrawMenu();
		void DrawInstructions();
		void DrawLobby();
	};
}