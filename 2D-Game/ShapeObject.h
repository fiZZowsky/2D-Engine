#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

/**@brief
	* Klasa bazowa dla obiektow, które s¹ kszta³tami
	*/
class ShapeObject : public virtual DrawableObject, public virtual TransformableObject
{

};