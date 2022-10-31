#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer() {
	/*drawLine();*/
	/*drawSFMLLine();*/
}

PrimitiveRenderer::~PrimitiveRenderer() {}

sf::RectangleShape PrimitiveRenderer::drawRectangle(int x, int y, int width, int height,
	sf::Color outlineColor, sf::Color fillColor){


	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(x, y);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setFillColor(fillColor);
	return rectangle;
}

sf::CircleShape PrimitiveRenderer::drawCircle(int x, int y, int radius,
	sf::Color outlineColor, sf::Color fillColor){

	sf::CircleShape circle(radius);
	circle.setPosition(x, y);
	circle.setOutlineColor(outlineColor);
	circle.setFillColor(fillColor);
	return circle;
}

sf::CircleShape PrimitiveRenderer::drawTriangle(int x, int y, int edgeSize, 
	sf::Color outlineColor, sf::Color fillColor) {

	sf::CircleShape triangle(edgeSize, 3);
	triangle.setPosition(x,y);

	triangle.setFillColor(fillColor);
	triangle.setOutlineColor(outlineColor);
	return triangle;
}

//void PrimitiveRenderer::drawLine(int x0, int y0, int x1, int y1) {
//	//incremental algorithm
//	sf::Vector2f deltaPos;
//	int x0 = 0;
//	int y0 = 2;
//	int x1 = 10;
//	int y1 = 4;
//	float m = 0;
//	int counter = 1;
//
//	deltaPos.x = x1 - x0;
//	deltaPos.y = y1 - y0;
//	m = deltaPos.y / deltaPos.x;
//
//	line.setPointCount(deltaPos.x + 1);
//	line.setPoint(0, sf::Vector2f(x0, y0));
//
//	while (counter <= deltaPos.x) {
//		line.setPoint(counter, deltaPos);
//		deltaPos.x += 1;
//		deltaPos.y += m;
//		counter++;
//	}
//}

//void PrimitiveRenderer::drawSFMLLine() {
//	SFMLline.setSize(sf::Vector2f(150, 1));
//	SFMLline.setPosition(sf::Vector2f(500, 500));
//	SFMLline.setFillColor(sf::Color::Black);
//	//SFMLline.rotate(45);
//}