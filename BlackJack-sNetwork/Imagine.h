#pragma once
#include "UI.h"
class Imagine :
	public UI::DrawableObject
{
public:
	Imagine();
	virtual ~Imagine();
	Imagine& operator*() {
		return *this;
	}
	 void Draw();
};

