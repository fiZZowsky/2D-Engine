#pragma once
#include "Headers.h"
/**@brief
	* Klasa bazowa dla obiektow, które mog¹ byæ animowane
	*/
class AnimatedObject
{
	/**@brief
	* Metoda pozwalaj¹ca na animacje obiektu
	* 
	* @param window
	*		Okno, w którym wyœwietlany jest obiekt
	*/
	virtual void animate(sf::RenderWindow* window) = 0;
};