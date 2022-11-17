#pragma once
#include "ShapeObject.h"

class Rectangle : protected virtual ShapeObject
{

private:
	sf::RectangleShape rectangle;

public:

	Rectangle(int x, int y, int width, int height, sf::Color color);
	void draw(sf::RenderWindow* window);
	void translate();
	void rotate();
	void scale();
};
