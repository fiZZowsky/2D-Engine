#include "Polygon.h"

Polygon::Polygon(int x, int y, int numberOfEdges, int edgeSize, sf::Color color) {
	polygon.setRadius(edgeSize);
	polygon.setPointCount(numberOfEdges);
	polygon.setPosition(x, y);
	polygon.setFillColor(color);
}

void Polygon::draw(sf::RenderWindow* window) {
	window->draw(polygon);
}

void Polygon::translate(sf::Vector2f offset) {
	polygon.move(offset);
}

void Polygon::rotate(float angle) {
	polygon.setRotation(angle);

}

void Polygon::scale(float factorX, float factorY) {
	polygon.setScale(factorX, factorY);

}

int Polygon::getX() {
	return polygon.getPosition().x;
}

int Polygon::getY() {
	return polygon.getPosition().y;
}

void Polygon::setX(int x) {
	polygon.setPosition(x, polygon.getPosition().y);
}

void Polygon::setY(int y) {
	polygon.setPosition(polygon.getPosition().x, y);
}