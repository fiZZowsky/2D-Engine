#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca wielok�t
	*/
class Polygon : public virtual ShapeObject
{
private:
	sf::CircleShape polygon;

public:
	Polygon(int x, int y, int numberOfEdges, int edgeSize, sf::Color color);

	/**@brief
	* Metoda rysuj�ca wielok�t
	*
	* @param window
	*	Okno, w kt�rym ma by� rysowany wielok�t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuni�cie wielok�ta o wektor
	*
	* @param offset
	*	Wektor przesuni�cia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obr�t wielok�ta
	*
	* @param angle
	*	K�t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie wielok�ta
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
	* Metoda zwracaj�ca pozycje X wielok�ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj�ca pozycje Y wielok�ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj�ca pozycje X wielok�ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj�ca pozycje Y wielok�ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};