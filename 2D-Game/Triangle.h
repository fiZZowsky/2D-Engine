#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca Trójk¹t
	*/
class Triangle : public virtual ShapeObject
{

private:
	sf::CircleShape triangle;

public:

	Triangle(int x, int y, int edgeSize, sf::Color color);

	/**@brief
	* Metoda rysuj¹ca trójk¹t
	*
	* @param window
	*	Okno, w którym ma byæ rysowany trójk¹t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuniêcie trójk¹ta o wektor
	*
	* @param offset
	*	Wektor przesuniêcia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obrót trójk¹ta
	*
	* @param angle
	*	K¹t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie trójk¹ta
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
	* Metoda zwracaj¹ca pozycje X trójk¹ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y trójk¹ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X trójk¹ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y trójk¹ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
