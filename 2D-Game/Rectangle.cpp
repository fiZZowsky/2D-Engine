#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, sf::Color color) {
	rectangle.setPosition(x, y);
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(color);
}

void Rectangle::draw(sf::RenderWindow* window) {
	window->draw(rectangle);
}

void Rectangle::translate(sf::Vector2f offset) {
	rectangle.move(offset);
}

void Rectangle::rotate(float angle) {
	rectangle.setRotation(angle);

}

void Rectangle::scale(float factorX, float factorY) {
	rectangle.setScale(factorX, factorY);

}

int Rectangle::getX() {
	return rectangle.getPosition().x;
}

int Rectangle::getY() {
	return rectangle.getPosition().y;
}

void Rectangle::setX(int x) {
	rectangle.setPosition(x, rectangle.getPosition().y);
}

void Rectangle::setY(int y) {
	rectangle.setPosition(rectangle.getPosition().x, y);
}