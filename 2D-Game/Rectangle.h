#pragma once
#include "ShapeObject.h"

/**@brief
	* Klasa reprezentujaca prostok¹t
	*/
class Rectangle : public virtual ShapeObject
{

private:
	sf::RectangleShape rectangle;

public:

	Rectangle(int x, int y, int width, int height, sf::Color color);

	/**@brief
	* Metoda rysuj¹ca prostok¹t
	*
	* @param window
	*	Okno, w którym ma byæ rysowany prostok¹t
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuniêcie prostok¹ta o wektor
	*
	* @param offset
	*	Wektor przesuniêcia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obrót prostok¹ta
	*
	* @param angle
	*	K¹t obrotu
	*/
	void rotate(float angle);

	/**@brief
	* Metoda pozwalajaca skalowanie prostok¹ta
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
	* Metoda zwracaj¹ca pozycje X prostok¹ta
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y prostok¹ta
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X prostok¹ta
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y prostok¹ta
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);
};
