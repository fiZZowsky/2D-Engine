#include "Triangle.h"

Triangle::Triangle(int x, int y, int edgeSize, sf::Color color) {
	triangle.setRadius(edgeSize);
	triangle.setPointCount(3);
	triangle.setPosition(x, y);
	triangle.setFillColor(color);
}

void Triangle::draw(sf::RenderWindow* window) {
	window->draw(triangle);
}

void Triangle::translate(sf::Vector2f offset) {
	triangle.move(offset);
}

void Triangle::rotate(float angle) {
	triangle.setRotation(angle);

}

void Triangle::scale(float factorX, float factorY) {
	triangle.setScale(factorX, factorY);

}