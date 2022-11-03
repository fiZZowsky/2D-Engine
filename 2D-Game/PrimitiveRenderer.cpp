#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer() {}

PrimitiveRenderer::~PrimitiveRenderer() {}

void PrimitiveRenderer::swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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

sf::RectangleShape PrimitiveRenderer::drawPixel(int x, int y, sf::Color color) {
	return drawRectangle(x, y, 1, 1, color, color);
}

sf::VertexArray PrimitiveRenderer::drawLine(int x1, int y1, int x2, int y2, sf::Color color) {
	sf::VertexArray line(sf::Lines, 2);

	line[0] = sf::Vertex(sf::Vector2f(x1, y1), color);
	line[1] = sf::Vertex(sf::Vector2f(x2, y2), color);

	return line;
}

sf::VertexArray drawLine(Point2D start, Point2D end, sf::Color color) {
	sf::VertexArray line(sf::Lines, 2);

	line[0] = sf::Vertex(sf::Vector2f(start.getX(), start.getY()), color);
	line[1] = sf::Vertex(sf::Vector2f(end.getX(), end.getY()), color);

	return line;
}

void PrimitiveRenderer::myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color) {
	if (x0 > x1) {
		swap(&x0, &x1);
	}

	float deltaY = abs(y1 - y0);
	float deltaX = abs(x1 - x0);

	float m = deltaY / deltaX;
	float x, y;
	float yi, xi;

	if (m <= 1) {

		for (int i = 0; i < deltaX; i++) {
			yi = m * i + y0;
			x = x0 + i;
			window->draw(drawPixel(x, round(yi), color));
		}
	}
	else {

		swap(&x0, &y0);
		swap(&x1, &y1);


		deltaY = abs(y1 - y0);
		deltaX = abs(x1 - x0);

		m = deltaY / deltaX;

		for (int i = 0; i < deltaX; i++) {
			xi = m * i + x0;
			y = y0 + i;
			window->draw(drawPixel(round(xi), y, color));
		}

	}
}


sf::RectangleShape PrimitiveRenderer::drawSFMLLine(int x, int y, int length, int rotation, sf::Color fillColor) {
	sf::RectangleShape SFMLline(sf::Vector2f(length, 1));
	SFMLline.setPosition(sf::Vector2f(x, y));
	SFMLline.setFillColor(fillColor);
	SFMLline.rotate(rotation);
	return SFMLline;
}