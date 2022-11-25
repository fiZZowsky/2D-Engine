#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca ko�o
	*/
class Circle : public virtual ShapeObject
{

private:
	sf::CircleShape circle;

public:

	Circle(int x, int y, int radius, sf::Color color);

	/**@brief
	* Metoda rysuj�ca ko�o
	* 
	* @param window
	*	Okno, w kt�rym ma by� rysowane ko�o
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuni�cie ko�a o wektor
	*
	* @param offset
	*	Wektor przesuni�cia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obr�t ko�a
	*
	* @param angle
	*	K�t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie ko�a
	*
	* @param factorX
	*	Wsp�czynnik skalowania wzgl�dem osi X
	*
	* @param factorY
	*	Wsp�czynnik skalowania wzgl�dem osi Y
	*
	*/
	void scale(float factorX, float factorY);

	/**@brief
	* Metoda zwracaj�ca pozycje X ko�a
	*/
	int getX();

	/**@brief
	* Metoda zwracaj�ca pozycje Y ko�a
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj�ca pozycje X ko�a
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj�ca pozycje Y ko�a
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
