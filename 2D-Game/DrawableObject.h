#pragma once
#include "GameObject.h"

class DrawableObject : public virtual GameObject
{
protected:

	virtual void draw(sf::RenderWindow* window) = 0;
};
