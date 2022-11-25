#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, które mog¹ byæ rysowane
	*/
class DrawableObject : public virtual GameObject
{
protected:

	/**@brief
	* Klasa bazowa dla obiektow, które mog¹ byæ rysowane
	* 
	* @param window
	*		Okno, w którym ma byæ rysowany obiekt
	*/
	virtual void draw(sf::RenderWindow* window) = 0;
};
