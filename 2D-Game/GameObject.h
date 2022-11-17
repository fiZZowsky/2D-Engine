#pragma once
#include "Headers.h"

class GameObject
{
public:
	virtual int getX() = 0;
	virtual int getY() = 0;

	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
};
