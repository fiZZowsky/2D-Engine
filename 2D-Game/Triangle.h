#pragma once
#include "ShapeObject.h"

class Triangle : public virtual ShapeObject
{

private:
	sf::CircleShape triangle;

public:

	Triangle(int x, int y, int edgeSize, sf::Color color);
	void draw(sf::RenderWindow* window);
	void translate(sf::Vector2f offset);
	void rotate(float angle);
	void scale(float factorX, float factorY);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
};
