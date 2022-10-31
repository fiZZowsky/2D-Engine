#pragma once
#include "Headers.h"

class PrimitiveRenderer{
public:
	PrimitiveRenderer();
	~PrimitiveRenderer();
		

	sf::RectangleShape drawRectangle(int x, int y, int width, int height,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawCircle(int x, int y, int radius,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawTriangle(int x, int y, int edgeSize,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawPolygon(int x, int y, int edgeSize, int sidesNumber = 3,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);
	/*void drawLine(int x0, int y0, int x1, int y1);*/


};