#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, sf::Color color) {
	rectangle.setPosition(x, y);
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(color);
}

void Rectangle::draw(sf::RenderWindow* window) {
	window->draw(rectangle);
}

void Rectangle::translate() {

}

void Rectangle::rotate() {

}

void Rectangle::scale() {

}