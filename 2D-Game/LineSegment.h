#pragma once

#include "Headers.h"
#include <cmath>
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"

class Point2D;
class PrimitiveRenderer;

class LineSegment : public virtual ShapeObject
{
private:
	Point2D* startPoint, * endPoint;
	PrimitiveRenderer* primitiveRenderer;
	sf::VertexArray segment;
	sf::Color color;

	static int crossProduct(Point2D* x, Point2D* y, Point2D* z);
	static bool isPointOnLineSegment(Point2D* x, Point2D* y, Point2D* z);

	void updateSegment();

public:
	static bool isLineSegmentsCrossing(LineSegment ls1, LineSegment ls2);

	LineSegment();
	LineSegment(Point2D* startPoint, Point2D* endPoint);
	LineSegment(Point2D* startPoint, Point2D* endPoint, sf::Color color);
	LineSegment(int x1, int y1, int x2, int y2);
	LineSegment(int x1, int y1, int x2, int y2, sf::Color color);

	void draw(sf::RenderWindow* window);
	void translate(sf::Vector2f offset);
	void rotate(float angle, sf::Vector2f point);
	void scale(float k, sf::Vector2f point);


	Point2D* getStartPoint();
	Point2D* getEndPoint();

	void setStartPoint(Point2D* point);
	void setEndPoint(Point2D* point);

	sf::Color getColor();
	void setColor(sf::Color color);

	sf::VertexArray draw(sf::Color color = sf::Color::Red);
	void drawWithIncrementalAlgorithm(sf::RenderWindow* window, sf::Color color = sf::Color::Red);

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

};