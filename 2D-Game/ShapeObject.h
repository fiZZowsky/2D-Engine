#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

/**@brief
	* Klasa bazowa dla obiektow, kt�re s� kszta�tami
	*/
class ShapeObject : public virtual DrawableObject, public virtual TransformableObject
{

};