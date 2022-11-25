#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca prostok�t
	*/
class Rectangle : public virtual ShapeObject
{

private:
	sf::RectangleShape rectangle;

public:

	Rectangle(int x, int y, int width, int height, sf::Color color);

	/**@brief
	* Metoda rysuj�ca prostok�t
	*
	* @param window
	*	Okno, w kt�rym ma by� rysowany prostok�t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuni�cie prostok�ta o wektor
	*
	* @param offset
	*	Wektor przesuni�cia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obr�t prostok�ta
	*
	* @param angle
	*	K�t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie prostok�ta
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
	* Metoda zwracaj�ca pozycje X prostok�ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj�ca pozycje Y prostok�ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj�ca pozycje X prostok�ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj�ca pozycje Y prostok�ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
