#pragma once
#include "GameObject.h"

/**@brief
	* Klasa bazowa dla obiektow, które mog¹ byæ przekszta³cane
	*/
class TransformableObject : public virtual GameObject
{
protected:

	/**@brief
	* Metoda pozwalajaca na przesuniêcie obiektu o wektor
	* 
	* @param offset
	*	Wektor przesuniêcia
	*/
	virtual void translate(sf::Vector2f offset) = 0;

	/**@brief
	* Metoda pozwalajaca obrót obiektu
	*
	* @param angle
	*	K¹t obrotu
	*/
	virtual void rotate(float angle) {};

	/**@brief
	* Metoda pozwalajaca obrót obiektu wokó³ punktu
	*
	* @param angle
	*	K¹t obrotu
	* 
	* @param point
	*	Punkt, wzglêdem którego obracany jest obiekt
	*/
	virtual void rotate(float angle, sf::Vector2f point) {};

	/**@brief
	* Metoda pozwalajaca skalowanie obiektu
	*
	* @param factorX
	*	Wspó³czynnik skalowania wzglêdem osi X
	* 
	* @param factorY
	*	Wspó³czynnik skalowania wzglêdem osi Y
	*
	*/
	virtual void scale(float factorX, float factorY) {};

	/**@brief
	* Metoda pozwalajaca skalowanie obiektu
	*
	* @param k
	*	Wspó³czynnik skalowania
	*
	* @param point
	*	Punkt jednok³adnoœci
	*
	*/
	virtual void scale(float k, sf::Vector2f point) {};
};