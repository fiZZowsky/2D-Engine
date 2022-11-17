#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject
{
protected:

	virtual void translate(sf::Vector2f offset) = 0;
	virtual void rotate(float angle) = 0;
	virtual void scale(float factorX, float factorY) = 0;
};