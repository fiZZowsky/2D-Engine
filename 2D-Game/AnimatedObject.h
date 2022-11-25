#pragma once
#include "Headers.h"
/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� animowane
	*/
class AnimatedObject
{
	/**@brief
	* Metoda pozwalaj�ca na animacje obiektu
	* 
	* @param window
	*		Okno, w kt�rym wy�wietlany jest obiekt
	*/
	virtual void animate(sf::RenderWindow* window) = 0;
};