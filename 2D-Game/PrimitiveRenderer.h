#pragma once
#include "Headers.h"
#include <cmath>

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
	
	sf::RectangleShape drawPixel(int x, int y, sf::Color color = sf::Color::Red);
	sf::VertexArray drawLine(int x1, int y1, int x2, int y2, sf::Color color = sf::Color::Red);

	void myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color = sf::Color::Red);

private:
	void swap(int* a, int* b);



	//void myDrawLine(x1, y1, x2, y2);
	/*void drawLine(int x0, int y0, int x1, int y1);*/


};