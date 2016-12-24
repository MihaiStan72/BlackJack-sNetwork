#include "ConcreteDrawableObjects.h"
#include <iostream>

using namespace ConcreteDrawableObjects;

Imagine::Imagine()
{
}

void Imagine::Draw() {
	std::cout << "Desenat Imagine";
}

Imagine::~Imagine()
{
}
