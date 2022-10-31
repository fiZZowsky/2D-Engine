#pragma once
#include "Headers.h"

class PrimitiveRender{
public:
	PrimitiveRender();
	~PrimitiveRender();
		
	/*sf::ConvexShape line;
	sf::RectangleShape SFMLline;*/

	sf::RectangleShape drawRectangle(int x, int y, int width, int height,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawCircle(int x, int y, int radius,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawTriangle(int x, int y, int edgeSize,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);
	/*void drawLine();*/
	/*void drawSFMLLine();*/
};