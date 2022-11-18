#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"

class PrimitiveRenderer; // forward declaration

class Point2D : public virtual ShapeObject{
	private: 
		static const int POINT_WIDTH = 10;
		static const int POINT_HEIGHT = 10;

		PrimitiveRenderer *primitiveRenderer;
		sf::RectangleShape point;
	public:
		Point2D();
		Point2D(int x, int y);
		Point2D(int x, int y, sf::Color color);

		int getX();
		int getY();
		void setX(int x);
		void setY(int y);

		sf::Color getColor();
		void setColor(sf::Color color);

		void setPoint(int x, int y);

		void draw(sf::RenderWindow* window);
		void translate(sf::Vector2f offset);
		void rotate(float angle);
		void scale(float factorX, float factorY);


		Point2D& operator= (const Point2D& point);
		bool operator == (const Point2D& point);
};