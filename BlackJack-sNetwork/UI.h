#pragma once
#include <list>
namespace UI {

	class DrawableObject {
	public:
		DrawableObject();
		~DrawableObject();

		void Draw();
	private:
		int x, y;
	};

	class DrawAgent {	
	public:
		DrawAgent();
		~DrawAgent();

		static DrawAgent* GetReference();
		static DrawAgent *instance;

		void UpdateFrame();

		void Add(DrawableObject* object);
		void Delete(DrawableObject* object);
	private:
		std::list<DrawableObject*> referenceList;
	
	};

	class Window {
	public:
		Window();
		virtual ~Window();
	};	


}