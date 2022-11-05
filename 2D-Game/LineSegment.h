#pragma once

#include "Headers.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"

class Point2D;
class PrimitiveRenderer;

class LineSegment {
private:
	Point2D* startPoint, * endPoint;
	PrimitiveRenderer* primitiveRenderer;

public:

	LineSegment();
	LineSegment(Point2D* startPoint, Point2D* endPoint);
	LineSegment(int x1, int y1, int x2, int y2);

	Point2D* getStartPoint();
	Point2D* getEndPoint();

	void setStartPoint(Point2D* point);
	void setEndPoint(Point2D* point);

	sf::VertexArray draw(sf::Color color = sf::Color::Red);
	void drawWithIncrementalAlgorithm(sf::RenderWindow* window, sf::Color color = sf::Color::Red);

};