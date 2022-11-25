#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca wielok¹t
	*/
class Polygon : public virtual ShapeObject
{
private:
	sf::CircleShape polygon;

public:
	Polygon(int x, int y, int numberOfEdges, int edgeSize, sf::Color color);

	/**@brief
	* Metoda rysuj¹ca wielok¹t
	*
	* @param window
	*	Okno, w którym ma byæ rysowany wielok¹t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuniêcie wielok¹ta o wektor
	*
	* @param offset
	*	Wektor przesuniêcia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obrót wielok¹ta
	*
	* @param angle
	*	K¹t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie wielok¹ta
	*
	* @param factorX
	*	Wspó³czynnik skalowania wzglêdem osi X
	*
	* @param factorY
	*	Wspó³czynnik skalowania wzglêdem osi Y
	*
	*/
	void scale(float factorX, float factorY);

	/**@brief
	* Metoda zwracaj¹ca pozycje X wielok¹ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y wielok¹ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X wielok¹ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y wielok¹ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};