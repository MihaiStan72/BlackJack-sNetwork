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
	private:
		std::string path;
	};
}
