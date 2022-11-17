#pragma once
#include "GameObject.h"

class DrawableObject : protected virtual GameObject
{
protected:

	virtual void draw(sf::RenderWindow* window) = 0;
};
