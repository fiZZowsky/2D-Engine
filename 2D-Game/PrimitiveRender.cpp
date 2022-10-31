#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer() {
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

sf::CircleShape PrimitiveRenderer::drawPolygon(int x, int y, int edgeSize, int sidesNumber,
	sf::Color outlineColor, sf::Color fillColor) {

	sf::CircleShape polygon(edgeSize, sidesNumber);
	polygon.setPosition(x, y);
	polygon.setFillColor(fillColor);
	polygon.setOutlineColor(outlineColor);
	return polygon;
}
//
//void PrimitiveRender::drawLine(int x0, int y0, int x1, int y1) {
//	//incremental algorithm
//	sf::ConvexShape polygon;
//	sf::Vector2f deltaPos;
//	float m = 0;
//	int counter = 1;
//	deltaPos.x = x1 - x0;
//	deltaPos.y = y1 - y0;
//	m = deltaPos.y / deltaPos.x;
//
//	polygon.setPointCount(deltaPos.x + 1);
//	polygon.setPoint(0, sf::Vector2f(x0, y0));
//
//	while (counter <= deltaPos.x) {
//		polygon.setPoint(counter, deltaPos);
//		deltaPos.x += 1;
//		deltaPos.y += m;
//		counter++;
//	}
//}
