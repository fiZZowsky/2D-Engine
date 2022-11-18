#include "Point2D.h"

Point2D::Point2D() {
	point.setPosition(0,0);
	point.setSize(sf::Vector2f(POINT_WIDTH, POINT_HEIGHT));
	point.setFillColor(sf::Color::Red);
}

Point2D::Point2D(int x, int y) {
	point.setPosition(x, y);
	point.setSize(sf::Vector2f(POINT_WIDTH, POINT_HEIGHT));
	point.setFillColor(sf::Color::Red);
}

Point2D::Point2D(int x, int y, sf::Color color) {
	point.setPosition(x, y);
	point.setSize(sf::Vector2f(POINT_WIDTH, POINT_HEIGHT));
	point.setFillColor(color);
}


void Point2D::draw(sf::RenderWindow* window) {
	window->draw(point);
}

void Point2D::translate(sf::Vector2f offset) {
	point.move(offset);
}

void Point2D::rotate(float angle) {
	point.setRotation(angle);
}

void Point2D::scale(float factorX, float factorY) {
	point.setScale(factorX, factorY);
}

int Point2D::getX() {
	return point.getPosition().x;
}
int Point2D::getY() {
	return point.getPosition().y;
}

void Point2D::setX(int x) {
	point.setPosition(x, point.getPosition().y);
}

void Point2D::setY(int y) {
	point.setPosition(point.getPosition().x, y);
}

sf::Color Point2D::getColor() {
	return point.getFillColor();
}
void Point2D::setColor(sf::Color color) {
	point.setFillColor(color);
}

void Point2D::setPoint(int x, int y) {
	point.setPosition(x, y);
}



Point2D& Point2D::operator = (const Point2D& point) {
	int newX = point.point.getPosition().x;
	int newY = point.point.getPosition().y;
	this->point.setPosition(newX, newY);
	return *this;
}

bool Point2D::operator == (const Point2D& point) {

	return this->getX() == point.point.getPosition().x && this->getY() == point.point.getPosition().y;
}
