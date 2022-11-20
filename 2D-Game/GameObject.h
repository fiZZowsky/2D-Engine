#pragma once
#include "Headers.h"

class GameObject
{
public:
	virtual int getX() { return 0; };
	virtual int getY() { return 0; };

	virtual void setX(int x) {};
	virtual void setY(int y) {};
};
