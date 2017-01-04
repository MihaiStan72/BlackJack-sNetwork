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
		void Draw(std::string path, float x, float y);
	};

	class Text : public UI::DrawableObject
	{
	public:
		Text();
		virtual ~Text();
		Text& operator*() {
			return *this;
		}
		void Draw();
		void Draw(std::string path, float x, float y);
	};
}
