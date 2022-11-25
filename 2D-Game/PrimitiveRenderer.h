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
	* Klasa pozwalajaca na rysowanie ró¿nych prymitytów i wype³nianie obszarów kolorem
	*/
class PrimitiveRenderer{
public:
	PrimitiveRenderer();
	~PrimitiveRenderer();

	Point2D *point;
		
	/**@brief
	* Metoda pozwalajaca na rysowanie prostok¹ta
	* 
	* @param x
	*	Pozycja x
	* 
	* @param y
	*	Pozycja y
	* 
	* @param width
	*	D³ugoœæ
	* 
	* @param height
	*	Szerokoœæ
	* 
	* @param outlineColor
	*	Kolor ramki
	* 
	* @param fillColor
	*	Kolor wype³nienia
	*/
	sf::RectangleShape drawRectangle(int x, int y, int width, int height,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie okrêgu
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param radius
	*	D³ugoœæ promienia
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype³nienia
	*/
	sf::CircleShape drawCircle(int x, int y, int radius,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie trójk¹ta
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param edgesize
	*	D³ugoœæ boku
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype³nienia
	*/
	sf::CircleShape drawTriangle(int x, int y, int edgeSize,
		sf::Color outlineColor = sf::Color::Black, sf::Color fillColor = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie wielok¹ta
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param edgesize
	*	D³ugoœæ boku
	* 
	* @param sideNumber
	*	Iloœæ boków wielok¹ta
	*
	* @param outlineColor
	*	Kolor ramki
	*
	* @param fillColor
	*	Kolor wype³nienia
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
	*	Pozycja x punktu pocz¹tkowego
	*
	* @param y1
	*	Pozycja y punktu pocz¹tkowego
	* 
	* @param x2
	*	Pozycja x punktu koñcowego
	*
	* @param y2
	*	Pozycja y punktu koñcowego
	*/
	sf::VertexArray drawLine(int x1, int y1, int x2, int y2, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii ³amanej
	*
	* @param points
	*	Zbiór punktów
	* 
	* @param color 
	*	Kolor
	*/
	sf::VertexArray drawPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii ³amanej
	*
	* @param lineSegments
	*	Zbiór odcinków
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii ³amanej zamkniêtej
	*
	* @param points
	*	Zbiór punktów
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawClosedPolyline(std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii ³amanej zamkniêtej
	*
	* @param lineSegments
	*	Zbiór odcinków
	*
	* @param color
	*	Kolor
	*/
	sf::VertexArray drawClosedPolyline(std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie linii algorytmem przyrostowym
	*
	* @param window
	*	Okno, w którym ma byæ narysowana linia
	* 
	* @param x0
	*	Pozycja x punktu pocz¹tkowego
	* 
	* @param y0
	*	Pozycja y punktu pocz¹tkowego
	* 
	* @param x1
	* 	Pozycja x punktu koñcowego
	* 
	* @param y1
	*	Pozycja y punktu koñcowego
	* 
	* @param color
	*	Kolor
	*/
	void myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie okrêgu wykorzystuj¹ca metodê czterokrotnej symetrii
	*
	* @param window
	*	Okno, w którym ma byæ narysowana linia
	*
	* @param x
	*	Pozycja x
	* 
	* @param y
	*	Pozycja y 
	* 
	* @param radius
	*	Promieñ
	*
	* @param color
	*	Kolor
	*/
	void myDrawCircle(sf::RenderWindow *window, int x, int y, int radius, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie elipsy wykorzystujaca metodê czterokrotnej symetrii
	*
	* @param window
	*	Okno, w którym ma byæ narysowane ko³o
	*
	* @param x
	*	Pozycja x
	*
	* @param y
	*	Pozycja y
	*
	* @param radiusX
	*	Promieñ X
	* 
	* @param radiusY
	*	Promieñ Y
	*
	* @param color
	*	Kolor
	*/
	void myDrawElipse(sf::RenderWindow* window, int x, int y, int radiusX, int radiusY, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie lini ³amanej
	*
	* @param window
	*	Okno, w którym ma byæ narysowana elipsa
	*
	* @param points
	*	Zbiór odcinków
	* 
	* @param color
	*	Kolor
	*/
	void myDrawPolygon(sf::RenderWindow* window, std::vector<Point2D> points, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na rysowanie lini ³amanej
	*
	* @param window
	*	Okno, w którym ma byæ narysowana linia
	*
	* @param lineSegments
	*	Zbiór odcinków
	*
	* @param color
	*	Kolor
	*/
	void myDrawPolygon(sf::RenderWindow* window, std::vector<LineSegment> lineSegments, sf::Color color = sf::Color::Red);

	/**@brief
	* Metoda pozwalajaca na wype³nianie obszaru kolorem, wykorzystuje metodê boundry fill
	*
	* @param window
	*	Okno, w którym ma byæ narysowana linia
	*
	* @param p
	*	Punkt, od którego ma zacz¹æ algorytm
	*
	* @param fillColor
	*	Kolor wype³nienia
	* 
	* @param boundryColor
	*	Kolor krawêdzi
	*/
	void boundryFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor, sf::Color boundryColor);

	/**@brief
	* Metoda pozwalajaca na wype³nianie obszaru kolorem, wykorzystuje metodê flood fill
	*
	* @param window
	*	Okno, w którym ma byæ narysowana linia
	*
	* @param p
	*	Punkt od którego ma zacz¹æ algorytm
	*
	* @param fillColor
	*	Kolor wype³nienia
	*/
	void floodFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor);

private:
	/**@brief
	* Metoda pomocnicza zamieniaj¹ca ze sob¹ wartoœci dwóch zmiennych typu int
	*
	* @param a
	*	WskaŸnik na zmienn¹ a
	*
	* @param b
	*	WskaŸnik na zmienn¹ b
	*
	*/
	void swap(int* a, int* b);

};