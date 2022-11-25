#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� aktualizowane
	*/
class UpdatableObject: protected virtual GameObject
{
protected:

	/**@brief
	* Metoda aktualizujaca obiekt
	* 
	* @param deltaTime
	*	Czas pomi�dzy klatkami
	*/
	virtual void update(float deltaTime) = 0;
};