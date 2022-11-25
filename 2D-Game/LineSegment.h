#pragma once

#include "Headers.h"
#include <cmath>
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"

class Point2D;
class PrimitiveRenderer;

/**@brief
	* Klasa reprezentujaca odcinek
	*/
class LineSegment : public virtual ShapeObject
{
private:
	Point2D* startPoint, * endPoint;
	PrimitiveRenderer* primitiveRenderer;
	sf::VertexArray segment;
	sf::Color color;

	/**@brief
	* Metoda obliczaj¹ca iloczyn wektorowy
	*/
	static int crossProduct(Point2D* x, Point2D* y, Point2D* z);

	/**@brief
	* Metoda sprawdzaj¹ca, czy punkt le¿y na odcinku
	* 
	* @param x
	*	Pocz¹tek odcinka
	* 
	* @param y
	*	Koniec odcinka
	* 
	* @param z
	*	Sprawdzany punkt
	*/
	static bool isPointOnLineSegment(Point2D* x, Point2D* y, Point2D* z);


	/**@brief
	* Metoda aktualizujaca odcinek
	*/
	void updateSegment();

public:
	static bool isLineSegmentsCrossing(LineSegment ls1, LineSegment ls2);

	LineSegment();
	LineSegment(Point2D* startPoint, Point2D* endPoint);
	LineSegment(Point2D* startPoint, Point2D* endPoint, sf::Color color);
	LineSegment(int x1, int y1, int x2, int y2);
	LineSegment(int x1, int y1, int x2, int y2, sf::Color color);

	/**@brief
	* Metoda rysuj¹ca odcinek
	*
	* @param window
	*	Okno, w którym ma byæ rysowany odcinek
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda pozwalajaca na przesuniêcie odcinka o wektor
	*
	* @param offset
	*	Wektor przesuniêcia
	*/
	void translate(sf::Vector2f offset);

	/**@brief
	* Metoda pozwalajaca obrót odcinka wokó³ punktu
	*
	* @param angle
	*	K¹t obrotu
	*
	* @param point
	*	Punkt, wzglêdem którego obracany jest odcinek
	*/
	void rotate(float angle, sf::Vector2f point);

	/**@brief
	* Metoda pozwalajaca skalowanie odcinka
	*
	* @param k
	*	Wspó³czynnik skalowania
	*
	* @param point
	*	Punkt jednok³adnoœci
	*
	*/
	void scale(float k, sf::Vector2f point);

	/**@brief
	* Metoda zwracaj¹ca pocz¹tek odcinka
	*/
	Point2D* getStartPoint();

	/**@brief
	* Metoda zwracaj¹ca koniec odcinka
	*/
	Point2D* getEndPoint();

	/**@brief
	* Metoda ustawiajaca pocz¹tek odcinka
	* 
	* @param point
	*	punkt pocz¹tkowy odcinka
	*/
	void setStartPoint(Point2D* point);

	/**@brief
	* Metoda ustawiajaca koniec odcinka
	*
	* @param point
	*	punkt koñcowy odcinka
	*/
	void setEndPoint(Point2D* point);

	/**@brief
	* Metoda zwracaj¹ca kolor odcinka
	*/
	sf::Color getColor();

	/**@brief
	* Metoda ustawiajaca kolor odcinka
	*
	* @param color
	*	Kolor odcinka
	*/
	void setColor(sf::Color color);

	/**@brief
	* Metoda pozwalaj¹ca na rysowanie odcinka
	*
	* @param color
	*	Kolor odcinka
	*/
	sf::VertexArray draw(sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalaj¹ca na rysowanie odcinka algorytmem przyrostowym
	*
	* @param window
	*	Okno, w którym ma byæ rysowany odcinek
	* 
	* @param color
	*	Kolor odcinka
	*/
	void drawWithIncrementalAlgorithm(sf::RenderWindow* window, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda zwracaj¹ca pozycje X odcinka
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y odcinka
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X odcinka
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y odcinka
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);

};