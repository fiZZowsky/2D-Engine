#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca Tr�jk�t
	*/
class Triangle : public virtual ShapeObject
{

private:
	sf::CircleShape triangle;

public:

	Triangle(int x, int y, int edgeSize, sf::Color color);

	/**@brief
	* Metoda rysuj�ca tr�jk�t
	*
	* @param window
	*	Okno, w kt�rym ma by� rysowany tr�jk�t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuni�cie tr�jk�ta o wektor
	*
	* @param offset
	*	Wektor przesuni�cia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obr�t tr�jk�ta
	*
	* @param angle
	*	K�t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie tr�jk�ta
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
	* Metoda zwracaj�ca pozycje X tr�jk�ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj�ca pozycje Y tr�jk�ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj�ca pozycje X tr�jk�ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj�ca pozycje Y tr�jk�ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
