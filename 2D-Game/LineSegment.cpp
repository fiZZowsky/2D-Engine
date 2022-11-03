#include "LineSegment.h"

LineSegment::LineSegment() {}

LineSegment::LineSegment(Point2D startPoint, Point2D endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

LineSegment::LineSegment(int x1, int y1, int x2, int y2) {
	startPoint.setPoint(x1, y1);
	endPoint.setPoint(x2, y2);
}

Point2D LineSegment::getStartPoint() {
	return this->startPoint;
}
Point2D LineSegment::getEndPoint() {
	return this->endPoint;
}

void LineSegment::setStartPoint(Point2D point) {
	this->startPoint = point;
}
void LineSegment::setEndPoint(Point2D point) {
	this->endPoint = point;
}

sf::VertexArray LineSegment::drawLineSegment() {
	return primitiveRenderer.drawLine()
}