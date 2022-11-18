#include "LineSegment.h"


// iloczyn wektorowy
int LineSegment::crossProduct(Point2D *x, Point2D *y, Point2D *z)
{
	int x1 = z->getX() - x->getX(), y1 = z->getY() - x->getY(),
		x2 = y->getX() - x->getX(), y2 = y->getY() - x->getY();
	return x1 * y2 - x2 * y1;
}

//sprawdzenie, czy punkt Z(koniec odcinka pierwszego)
//le¿y na odcinku XY 
bool LineSegment::isPointOnLineSegment(Point2D *x, Point2D *y, Point2D *z)
{
	//jezeli punkt Z jest rowny jednemu z koncow odcinka to uznajemy, ze nie lezy na nim
	if (*z == *x || *z == *y) {
		return false;
	}

	return std::min(x->getX(), y->getX()) <= z->getX() && z->getX() <= std::max(x->getX(), y->getX())
		&& std::min(x->getY(), y->getY()) <= z->getY() && z->getY() <= std::max(x->getY(), y->getY());
}

bool LineSegment::isLineSegmentsCrossing(LineSegment ls1, LineSegment ls2) {

	Point2D* A = ls1.getStartPoint();
	Point2D* B = ls1.getEndPoint();
	Point2D* C = ls2.getStartPoint();
	Point2D* D = ls2.getEndPoint();

	int v1 = LineSegment::crossProduct(C, D, A),
		v2 = LineSegment::crossProduct(C, D, B),
		v3 = LineSegment::crossProduct(A, B, C),
		v4 = LineSegment::crossProduct(A, B, D);

	//sprawdzenie czy siê przecinaj¹ - dla niedu¿ych liczb
	//if(v1*v2 < 0 && v3*v4 < 0) return 1;

	//sprawdzenie czy siê przecinaj¹ - dla wiêkszych liczb
	if ((v1 > 0 && v2 < 0 || v1 < 0 && v2>0) && (v3 > 0 && v4 < 0 || v3 < 0 && v4>0)) return 1;

	//sprawdzenie, czy koniec odcinka le¿y na drugim
	if (v1 == 0 && LineSegment::isPointOnLineSegment(C, D, A)) return true;
	if (v2 == 0 && LineSegment::isPointOnLineSegment(C, D, B)) return true;
	if (v3 == 0 && LineSegment::isPointOnLineSegment(A, B, C)) return true;
	if (v4 == 0 && LineSegment::isPointOnLineSegment(A, B, D)) return true;

	//odcinki nie maj¹ punktów wspólnych
	return false;
}

LineSegment::LineSegment() {
	startPoint = new Point2D(0, 0);
	endPoint = new Point2D(1, 0);

	this->segment.setPrimitiveType(sf::LineStrip);
	this->segment.resize(2);

	updateSegment();
}

LineSegment::LineSegment(Point2D* startPoint, Point2D* endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;

	this->segment.setPrimitiveType(sf::LineStrip);
	this->segment.resize(2);

	updateSegment();
}

LineSegment::LineSegment(Point2D* startPoint, Point2D* endPoint, sf::Color color) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->color = color;

	this->segment.setPrimitiveType(sf::LineStrip);
	this->segment.resize(2);

	segment[0].position = sf::Vector2f(startPoint->getX(), startPoint->getY());
	segment[0].color = color;
	segment[1].position = sf::Vector2f(endPoint->getX(), endPoint->getY());
	segment[1].color = color;
}

LineSegment::LineSegment(int x1, int y1, int x2, int y2) {
	startPoint = new Point2D(x1, y1);
	endPoint = new Point2D(x2, y2);

	this->segment.setPrimitiveType(sf::LineStrip);
	this->segment.resize(2);

	updateSegment();
}

LineSegment::LineSegment(int x1, int y1, int x2, int y2, sf::Color color) {
	startPoint = new Point2D(x1, y1);
	endPoint = new Point2D(x2, y2);
	this->color = color;

	this->segment.setPrimitiveType(sf::LineStrip);
	this->segment.resize(2);

	segment[0].position = sf::Vector2f(startPoint->getX(), startPoint->getY());
	segment[0].color = color;
	segment[1].position = sf::Vector2f(endPoint->getX(), endPoint->getY());
	segment[1].color = color;
}

void LineSegment::draw(sf::RenderWindow* window) {
	window->draw(segment);
}
void LineSegment::translate(sf::Vector2f offset) {
	startPoint->translate(offset);
	endPoint->translate(offset);

	updateSegment();
}
void LineSegment::rotate(float angle, sf::Vector2f point) {
	startPoint->rotate(angle, point);
	endPoint->rotate(angle, point);

	updateSegment();
}

void LineSegment::scale(float k, sf::Vector2f point) {
	int x2a = startPoint->getX() * k + (1 - k) * point.x;
	int y2a = startPoint->getY() * k + (1 - k) * point.y;

	int x2b = endPoint->getX() * k + (1 - k) * point.x;
	int y2b = endPoint->getY() * k + (1 - k) * point.y;

	startPoint->setX(x2a);
	startPoint->setY(y2a);

	endPoint->setX(x2b);
	endPoint->setY(y2b);
	
	updateSegment();
}

void LineSegment::updateSegment() {
	segment[0].position = sf::Vector2f(startPoint->getX(), startPoint->getY());
	segment[1].position = sf::Vector2f(endPoint->getX(), endPoint->getY());
}

Point2D* LineSegment::getStartPoint() {
	return this->startPoint;
}
Point2D* LineSegment::getEndPoint() {
	return this->endPoint;
}

void LineSegment::setStartPoint(Point2D* point) {
	this->startPoint = point;
}
void LineSegment::setEndPoint(Point2D* point) {
	this->endPoint = point;
}

sf::Color LineSegment::getColor() {
	return color;
}
void LineSegment::setColor(sf::Color color) {
	this->color = color;
}

sf::VertexArray LineSegment::draw(sf::Color color) {
	return primitiveRenderer->drawLine(startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), color);
}

void LineSegment::drawWithIncrementalAlgorithm(sf::RenderWindow* window, sf::Color color) {
	primitiveRenderer->myDrawLine(window, startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), color);
}


int LineSegment::getX() {
	return startPoint->getX();
};

int LineSegment::getY() {
	return startPoint->getY();
};
void LineSegment::setX(int x) {
	startPoint->setX(x);
};
void LineSegment::setY(int y) {
	startPoint->setY(y);
};