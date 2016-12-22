#pragma once
#include <list>
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
		Window();
		virtual ~Window();
	};	


}