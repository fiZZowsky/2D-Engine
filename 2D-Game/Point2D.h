#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"

class Point2D{
	private: 
		PrimitiveRenderer primitiveRenderer;
	public:
		Point2D();
		Point2D(int x, int y);

		~Point2D();

		sf::Vector2i point;

		sf::Vector2i getPoint();
		void setPoint(int x, int y);
		sf::RectangleShape drawPoint();
};