#pragma once
#include "Headers.h"

class PrimitiveRender{
public:
	PrimitiveRender();
	~PrimitiveRender();
		
	sf::CircleShape circle;
	sf::RectangleShape rectangle;

	void drawRectangle();
	void drawCircle();
	/*void drawTriangle();*/
	/*void drawLine(int x0, int y0, int x1, int y1);*/

private:
	int x0;
	int y0;
	int x1;
	int y1;
};