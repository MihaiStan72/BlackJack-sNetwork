#pragma once
#include <list>
namespace UI {

	class DrawableObject {
	public:
		DrawableObject();
		~DrawableObject();

		void Draw();
	private:

	};

	class DrawAgent {	
	public:
		DrawAgent();
		~DrawAgent();

		static DrawAgent Singleton();

		void UpdateFrame();
	private:
		std::list<DrawableObject*> referenceList;
	
	};

	class Window {
	public:
		Window();
		virtual ~Window();
	};	


}