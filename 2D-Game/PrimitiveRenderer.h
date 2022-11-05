#pragma once
#include "Headers.h"
#include <cmath>
#include <vector>
#include "Point2D.h"
#include "LineSegment.h"

#define M_PI 3.14159265358979323846

class Point2D; //forward declaration
class LineSegment;


class PrimitiveRenderer {
public:
	PrimitiveRenderer();
	~PrimitiveRenderer();

	Point2D* point; //need pointers to work


	sf::RectangleShape drawRectangle(int x, int y, int width, int height,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawCircle(int x, int y, int radius,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawTriangle(int x, int y, int edgeSize,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::CircleShape drawPolygon(int x, int y, int edgeSize, int sidesNumber = 3,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	sf::RectangleShape drawPixel(int x, int y, sf::Color color = sf::Color::Red);
	sf::RectangleShape drawPixel(Point2D* point, sf::Color color = sf::Color::Red);
	sf::VertexArray drawLine(int x1, int y1, int x2, int y2, sf::Color color = sf::Color::Red);

	sf::VertexArray drawPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);
	sf::VertexArray drawPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	sf::VertexArray drawClosedPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);
	sf::VertexArray drawClosedPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);
	//sf::VertexArray drawLine(Point2D start, Point2D end, sf::Color color = sf::Color:);
	sf::RectangleShape drawSFMLLine(int x, int y, int length, int rotation, sf::Color fillColor = sf::Color::Red);

	void myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color = sf::Color::Red);
	void myDrawCircle(sf::RenderWindow* window, int x, int y, int radius, sf::Color color = sf::Color::Red);
	void myDrawElipse(sf::RenderWindow* window, int x, int y, int radiusX, int radiusY, sf::Color color = sf::Color::Red);
	void myDrawPolygon(sf::RenderWindow* window, std::vector<Point2D> points, sf::Color color = sf::Color::Red);
	void myDrawPolygon(sf::RenderWindow* window, std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	void boundryFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor, sf::Color boundryColor);
	void floodFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor);

private:
	void swap(int* a, int* b);

	/*sf::ConvexShape drawLine(int x0, int y0, int x1, int y1, sf::Color fillColor = sf::Color::Red);*/

};