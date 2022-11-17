#pragma once
#include "GameObject.h"

class TransformableObject : protected virtual GameObject
{
protected:

	virtual void translate() = 0;
	virtual void rotate() = 0;
	virtual void scale() = 0;
};