#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"

class PrimitiveRenderer; // forward declaration

class Point2D{
	private: 
		int x, y;
		PrimitiveRenderer *primitiveRenderer;
	public:
		Point2D();
		Point2D(int x, int y);

		~Point2D();

		int getX();
		int getY();
		void setPoint(int x, int y);
		sf::RectangleShape drawPoint();

		Point2D& operator= (const Point2D& point);
		bool operator == (const Point2D& point);
};