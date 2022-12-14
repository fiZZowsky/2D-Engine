#pragma once
#include "Headers.h"

/**@brief
	* Klasa bazowa wszystkich obiektów gry
	*/
class GameObject
{
public:

	/**@brief
	* Metoda zwracająca pozycje X obiektu
	*/
	virtual int getX() { return 0; };


	/**@brief
	* Metoda zwracająca pozycje Y obiektu
	*/
	virtual int getY() { return 0; };


	/**@brief
	* Metoda ustawiająca pozycje X obiektu
	* 
	* @param x
	*	Nowa pozycja X
	*/
	virtual void setX(int x) {};

	/**@brief
	* Metoda ustawiająca pozycje Y obiektu
	*
	* @param y
	*	Nowa pozycja Y
	*/
	virtual void setY(int y) {};
};
