#pragma once
#include "ShapeObject.h"

class Polygon : public virtual ShapeObject
{
private:
	sf::CircleShape polygon;

public:
	Polygon(int x, int y, int numberOfEdges, int edgeSize, sf::Color color);

	void draw(sf::RenderWindow* window);
	void translate(sf::Vector2f offset);
	void rotate(float angle);
	void scale(float factorX, float factorY);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
};