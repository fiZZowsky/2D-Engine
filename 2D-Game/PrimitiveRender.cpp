#include "PrimitiveRender.h"

PrimitiveRender::PrimitiveRender() {
	drawRectangle();
	drawCircle();
	//drawTriangle();
	//drawLine(x0, y0, x1, y1);
}

PrimitiveRender::~PrimitiveRender() {}

void PrimitiveRender::drawRectangle() {
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setPosition(500, 500);
	rectangle.setFillColor(sf::Color::Magenta);
}

void PrimitiveRender::drawCircle() {
	circle.setRadius(50);
	circle.setOutlineColor(sf::Color::Black);
	circle.setPosition(700, 700);
	circle.setFillColor(sf::Color::Cyan);
}

//void PrimitiveRender::drawTriangle() {
//	sf::CircleShape triangle(x0, y0);
//	triangle.setPosition(300, 300);
//	triangle.setOutlineColor(sf::Color::Black);
//	triangle.setFillColor(sf::Color::Green);
//}
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
