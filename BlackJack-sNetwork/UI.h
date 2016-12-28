#pragma once
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


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

	class Window {
	public:
		virtual ~Window();
		
		static Window& GetReference() {
			static Window instance;

			SFML::window.create(sf::VideoMode::getDesktopMode(), "BlackJack's Network", sf::Style::None);

			return instance;
		}
	private:
		Window();
		Window(Window const&);//do not implement
		void operator=(Window const&);//do not implement
	};	


}