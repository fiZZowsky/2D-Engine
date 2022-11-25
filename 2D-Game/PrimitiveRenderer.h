#pragma once
#include "Headers.h"
#include <cmath>
#include <vector>
#include "Point2D.h"
#include "LineSegment.h"

#define M_PI 3.14159265358979323846

class Point2D; //forward declaration
class LineSegment;

/**@brief
	* Klasa pozwalajaca na rysowanie r�nych prymityt�w i wype�nianie obszar�w kolorem
	*/
class PrimitiveRenderer{
public:
	PrimitiveRenderer();
	~PrimitiveRenderer();

	Point2D *point;
		
	/**@brief
	* Metoda pozwalajaca na rysowanie prostok�ta
	* 
	* @param x
	*	Pozycja x
	* 
	* @param y
	*	Pozycja y
	* 
	* @param width
	*	D�ugo��
	* 
	* @param height
	*	Szeroko��
	* 
	* @param outlineColor
	*	Kolor ramki
	* 
	* @param fillColor
	*	Kolor wype�nienia
	*/
	sf::RectangleShape drawRectangle(int x, int y, int width, int height,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie okr�gu
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param radius
	*	D�ugo�� promienia
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype�nienia
	*/
	sf::CircleShape drawCircle(int x, int y, int radius,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie tr�jk�ta
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param edgesize
	*	D�ugo�� boku
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype�nienia
	*/
	sf::CircleShape drawTriangle(int x, int y, int edgeSize,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie wielok�ta
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param edgesize
	*	D�ugo�� boku
	* 
	* @param sideNumber
	*	Ilo�� bok�w wielok�ta
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype�nienia
	*/
	sf::CircleShape drawPolygon(int x, int y, int edgeSize, int sidesNumber = 3,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie piksela
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param color
	*	Kolor
	*/
	sf::RectangleShape drawPixel(int x, int y, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie piksela
	*
	* @param point
	*	Punkt
	*
	* @param color
	*	Kolor
	*/
	sf::RectangleShape drawPixel(Point2D *point, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii
	*
	* @param x1
	*	Pozycja x punktu pocz�tkowego
	*
	* @param y1
	*	Pozycja y punktu pocz�tkowego
	* 
	* @param x2
	*	Pozycja x punktu ko�cowego
	*
	* @param y2
	*	Pozycja y punktu ko�cowego
	*/
	sf::VertexArray drawLine(int x1, int y1, int x2, int y2, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii �amanej
	*
	* @param points
	*	Zbi�r punkt�w
	* 
	* @param color 
	*	Kolor
	*/
	sf::VertexArray drawPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii �amanej
	*
	* @param lineSegments
	*	Zbi�r odcink�w
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii �amanej zamkni�tej
	*
	* @param points
	*	Zbi�r punkt�w
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawClosedPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii �amanej zamkni�tej
	*
	* @param lineSegments
	*	Zbi�r odcink�w
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawClosedPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii algorytmem przyrostowym
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana linia
	* 
	* @param x0
	*	Pozycja x punktu pocz�tkowego
	* 
	* @param y0
	*	Pozycja y punktu pocz�tkowego
	* 
	* @param x1
	* 	Pozycja x punktu ko�cowego
	* 
	* @param y1
	*	Pozycja y punktu ko�cowego
	* 
	* @param color
	*	Kolor
	*/
	void myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie okr�gu wykorzystuj�ca metod� czterokrotnej symetrii
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana linia
	*
	* @param x
	*	Pozycja x
	* 
	* @param y
	*	Pozycja y 
	* 
	* @param radius
	*	Promie�
	*
	* @param color
	*	Kolor
	*/
	void myDrawCircle(sf::RenderWindow *window, int x, int y, int radius, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie elipsy wykorzystujaca metod� czterokrotnej symetrii
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowane ko�o
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param radiusX
	*	Promie� X
	* 
	* @param radiusY
	*	Promie� Y
	*
	* @param color
	*	Kolor
	*/
	void myDrawElipse(sf::RenderWindow* window, int x, int y, int radiusX, int radiusY, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie lini �amanej
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana elipsa
	*
	* @param points
	*	Zbi�r odcink�w
	* 
	* @param color
	*	Kolor
	*/
	void myDrawPolygon(sf::RenderWindow* window, std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie lini �amanej
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana linia
	*
	* @param lineSegments
	*	Zbi�r odcink�w
	*
	* @param color
	*	Kolor
	*/
	void myDrawPolygon(sf::RenderWindow* window, std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na wype�nianie obszaru kolorem, wykorzystuje metod� boundry fill
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana linia
	*
	* @param p
	*	Punkt, od kt�rego ma zacz�� algorytm
	*
	* @param fillColor
	*	Kolor wype�nienia
	* 
	* @param boundryColor
	*	Kolor kraw�dzi
	*/
	void boundryFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor, sf::Color boundryColor);

	/**@brief
	* Metoda pozwalajaca na wype�nianie obszaru kolorem, wykorzystuje metod� flood fill
	*
	* @param window
	*	Okno, w kt�rym ma by� narysowana linia
	*
	* @param p
	*	Punkt od kt�rego ma zacz�� algorytm
	*
	* @param fillColor
	*	Kolor wype�nienia
	*/
	void floodFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor);

private:
	/**@brief
	* Metoda pomocnicza zamieniaj�ca ze sob� warto�ci dw�ch zmiennych typu int
	*
	* @param a
	*	Wska�nik na zmienn� a
	*
	* @param b
	*	Wska�nik na zmienn� b
	*
	*/
	void swap(int* a, int* b);

};