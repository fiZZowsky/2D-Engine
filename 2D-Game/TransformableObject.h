#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject
{
protected:

	virtual void translate(sf::Vector2f offset) = 0;
	virtual void rotate(float angle) {};
	virtual void rotate(float angle, sf::Vector2f point) {};
	virtual void scale(float factorX, float factorY) {};
	virtual void scale(float k, sf::Vector2f point) {};
};