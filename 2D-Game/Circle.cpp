#include "Circle.h"

Circle::Circle(int x, int y, int radius, sf::Color color) {
	circle.setPosition(x, y);
	circle.setRadius(radius);
	circle.setFillColor(color);
}

void Circle::draw(sf::RenderWindow* window) {
	window->draw(circle);
}

void Circle::translate(sf::Vector2f offset) {
	circle.move(offset);
}

void Circle::rotate(float angle) {
	circle.setRotation(angle);
}

void Circle::scale(float factorX, float factorY) {
	circle.setScale(factorX, factorY);
}

int Circle::getX() {
	return circle.getPosition().x;
}

int Circle::getY() {
	return circle.getPosition().y;
}

void Circle::setX(int x) {
	circle.setPosition(x, circle.getPosition().y);
}

void Circle::setY(int y) {
	circle.setPosition(circle.getPosition().x, y);
}
