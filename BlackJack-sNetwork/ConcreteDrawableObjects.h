#pragma once

#include "UI.h"
#include <string>

namespace ConcreteDrawableObjects {
	
	class Imagine : public UI::DrawableObject
	{
	public:
		Imagine();
		virtual ~Imagine();
		Imagine& operator*() {
			return *this;
		}
		void Draw();
		void Draw(std::string path, int x, int y);
	};
}
