#include "Point2D.h"

Point2D::Point2D() {
	x = 0;
	y = 0;
}

Point2D::Point2D(int x, int y) {
	this->x = x;
	this->y = y;
}

Point2D::~Point2D() {}

int Point2D::getX() {
	return this->x;
}
int Point2D::getY() {
	return this->y;
}



void Point2D::setPoint(int x, int y) {
	this->x = x;
	this->y = y;
}

sf::RectangleShape Point2D::drawPoint() {
	return primitiveRenderer.drawRectangle(x, y, 10, 10);
}

Point2D& Point2D::operator = (const Point2D& point) {
	this->x = point.x;
	this->y = point.y;
}
