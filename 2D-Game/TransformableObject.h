#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� przekszta�cane
	*/
class TransformableObject : public virtual GameObject
{
protected:

	/**@brief
	* Metoda pozwalajaca na przesuni�cie obiektu o wektor
	* 
	* @param offset
	*	Wektor przesuni�cia
	*/
	virtual void translate(sf::Vector2f offset) = 0;

	/**@brief
	* Metoda pozwalajaca obr�t obiektu
	*
	* @param angle
	*	K�t obrotu
	*/
	virtual void rotate(float angle) {};

	/**@brief
	* Metoda pozwalajaca obr�t obiektu wok� punktu
	*
	* @param angle
	*	K�t obrotu
	* 
	* @param point
	*	Punkt, wzgl�dem kt�rego obracany jest obiekt
	*/
	virtual void rotate(float angle, sf::Vector2f point) {};

	/**@brief
	* Metoda pozwalajaca skalowanie obiektu
	*
	* @param factorX
	*	Wsp�czynnik skalowania wzgl�dem osi X
	* 
	* @param factorY
	*	Wsp�czynnik skalowania wzgl�dem osi Y
	*
	*/
	virtual void scale(float factorX, float factorY) {};

	/**@brief
	* Metoda pozwalajaca skalowanie obiektu
	*
	* @param k
	*	Wsp�czynnik skalowania
	*
	* @param point
	*	Punkt jednok�adno�ci
	*
	*/
	virtual void scale(float k, sf::Vector2f point) {};
};