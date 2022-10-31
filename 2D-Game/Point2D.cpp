#include "Point2D.h"

Point2D::Point2D() {
	point.x = 900;
	point.y = 900;
}

Point2D::~Point2D() {}

sf::Vector2i Point2D::getPoint() {
	return point;
}

void Point2D::setPoint(int x, int y) {
	this->point.x = x;
	this->point.y = y;
}

void Point2D::drawPoint() {
	drawRectangle(point.x, point.y, 1, 1);
}
