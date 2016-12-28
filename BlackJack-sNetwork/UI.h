#pragma once
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
namespace UI {

	class DrawableObject {
	public:
		DrawableObject();
		virtual ~DrawableObject();

		virtual void Draw() = 0;
		bool operator==(DrawableObject const&) {
			return true;
		}
	private:
		int x, y;
	};

	class DrawAgent {	
	public:
		
		~DrawAgent();

		static DrawAgent& GetReference() {
			static DrawAgent instance;
			return instance;
		}

		void UpdateFrame();

		void Add(DrawableObject* object);
		void Delete(DrawableObject* object);
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

		sf::Window* getWindow(int index);
		void CreateWindow();
		void CloseWindow(int index);
		virtual ~WindowManager();

	private:
		std::list<sf::Window*>windowList;	

		WindowManager();
		WindowManager(WindowManager const&);//do not implement
		void operator=(WindowManager const&);//do not implement
	};	


}