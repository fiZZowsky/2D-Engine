#include "Point2D.h"

Point2D::Point2D() {
	point.x = 0;
	point.y = 0;
}

Point2D::Point2D(int x, int y) {
	point.x = x;
	point.y = y;
}

Point2D::~Point2D() {}

sf::Vector2i Point2D::getPoint() {
	return point;
}



void Point2D::setPoint(int x, int y) {
	this->point.x = x;
	this->point.y = y;
}

sf::RectangleShape Point2D::drawPoint() {
	return primitiveRenderer.drawRectangle(point.x, point.y, 10, 10);
}
