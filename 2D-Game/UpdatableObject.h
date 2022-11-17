#pragma once
#include "GameObject.h"

class UpdatableObject: protected virtual GameObject
{
protected:
	virtual void update() = 0;
};