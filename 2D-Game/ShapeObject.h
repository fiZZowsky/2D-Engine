#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class ShapeObject : protected virtual DrawableObject, protected virtual TransformableObject
{

};