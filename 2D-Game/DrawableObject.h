#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� rysowane
	*/
class DrawableObject : public virtual GameObject
{
protected:

	/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� rysowane
	* 
	* @param window
	*		Okno, w kt�rym ma by� rysowany obiekt
	*/
	virtual void draw(sf::RenderWindow* window) = 0;
};
