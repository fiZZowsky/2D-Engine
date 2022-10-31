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

	/*sf::ConvexShape drawLine(int x0, int y0, int x1, int y1, sf::Color fillColor = sf::Color::Red);*/

	sf::RectangleShape drawSFMLLine(int x, int y, int length, int rotation, sf::Color fillColor = sf::Color::Red);
};