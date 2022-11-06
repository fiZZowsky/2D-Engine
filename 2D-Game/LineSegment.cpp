#include "LineSegment.h"

LineSegment::LineSegment() {
	startPoint = new Point2D(0, 0);
	endPoint = new Point2D(1, 0);
}

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

LineSegment::LineSegment(Point2D* startPoint, Point2D* endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

LineSegment::LineSegment(int x1, int y1, int x2, int y2) {
	startPoint = new Point2D(x1, y1);
	endPoint = new Point2D(x2, y2);
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

sf::VertexArray LineSegment::draw(sf::Color color) {
	return primitiveRenderer->drawLine(startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), color);
}

void LineSegment::drawWithIncrementalAlgorithm(sf::RenderWindow* window, sf::Color color) {
	primitiveRenderer->myDrawLine(window, startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), color);
}