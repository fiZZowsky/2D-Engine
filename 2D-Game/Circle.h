#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca ko³o
	*/
class Circle : public virtual ShapeObject
{

private:
	sf::CircleShape circle;

public:

	Circle(int x, int y, int radius, sf::Color color);

	/**@brief
	* Metoda rysuj¹ca ko³o
	* 
	* @param window
	*	Okno, w którym ma byæ rysowane ko³o
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuniêcie ko³a o wektor
	*
	* @param offset
	*	Wektor przesuniêcia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obrót ko³a
	*
	* @param angle
	*	K¹t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie ko³a
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
	* Metoda zwracaj¹ca pozycje X ko³a
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y ko³a
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X ko³a
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y ko³a
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
