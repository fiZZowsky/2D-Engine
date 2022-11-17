#pragma once
#include "ShapeObject.h"

class Rectangle : public virtual ShapeObject
{

private:
	sf::RectangleShape rectangle;

public:

	Rectangle(int x, int y, int width, int height, sf::Color color);
	void draw(sf::RenderWindow* window);
	void translate(sf::Vector2f offset);
	void rotate(float angle);
	void scale(float factorX, float factorY);
};
