#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"

class Point2D : PrimitiveRenderer{
	public:
		Point2D();
		~Point2D();

		sf::Vector2i point;
		//PrimitiveRenderer primitiveRenderer;

		sf::Vector2i getPoint();
		void setPoint(int x, int y);
		void drawPoint();
};