#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, które mog¹ byæ aktualizowane
	*/
class UpdatableObject: protected virtual GameObject
{
protected:

	/**@brief
	* Metoda aktualizujaca obiekt
	* 
	* @param deltaTime
	*	Czas pomiêdzy klatkami
	*/
	virtual void update(float deltaTime) = 0;
};