#pragma once

#include "Headers.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"

class LineSegment {
private:
	Point2D startPoint, endPoint;

public:

	LineSegment() {}
	LineSegment(Point2D startPoint, Point2D endPoint);
	LineSegment(int x1, int y1, int x2, int y2);

	Point2D getStartPoint();
	Point2D getEndPoint();

	void setStartPoint(Point2D point);
	void setEndPoint(Point2D point);
	
	sf::VertexArray drawLineSegment();

};