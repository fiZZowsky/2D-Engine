#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"

class PrimitiveRenderer; // forward declaration

/**@brief
	* Klasa reprezentuj�ca punkt
	*/
class Point2D : public virtual ShapeObject{
	private: 
		static const int POINT_WIDTH = 10;
		static const int POINT_HEIGHT = 10;

		PrimitiveRenderer *primitiveRenderer;
		sf::RectangleShape point;
	public:
		Point2D();
		Point2D(int x, int y);
		Point2D(int x, int y, sf::Color color);

		/**@brief
	* Metoda zwracaj�ca pozycje X punktu
	*/
		int getX();

		/**@brief
		* Metoda zwracaj�ca pozycje Y punktu
		*/
		int getY();

		/**@brief
		* Metoda ustawiaj�ca pozycje X punktu
		*
		* @param x
		*	Nowa pozycja X
		*/
		void setX(int x);

		/**@brief
		* Metoda ustawiaj�ca pozycje Y punktu
		*
		* @param y
		*	Nowa pozycja Y
		*/
		void setY(int y);

		/**@brief
		* Metoda zwracaj�ca kolor punktu
		*/
		sf::Color getColor();

		/**@brief
		* Metoda ustawiajaca kolor punktu
		*
		* @param color
		*	Kolor punktu
		*/
		void setColor(sf::Color color);

		/**@brief
		* Metoda ustawiajaca wsp�rz�dne odcinka
		*
		* @param x
		*	Wsp�rz�dna x
		* 
		* @param y
		*	Wsp�rz�dna y
		*	
		*/
		void setPoint(int x, int y);

		/**@brief
		* Metoda rysuj�ca punkt
		*
		* @param window
		*	Okno, w kt�rym ma by� rysowany punkt
		*/
		void draw(sf::RenderWindow* window);

		/**@brief
		* Metoda pozwalajaca na przesuni�cie punktu o wektor
		*
		* @param offset
		*	Wektor przesuni�cia
		*/
		void translate(sf::Vector2f offset);

		/**@brief
		* Metoda pozwalajaca obr�t punktu wok� punktu
		*
		* @param angle
		*	K�t obrotu
		*
		* @param point
		*	Punkt, wzgl�dem kt�rego obracany jest punkt
		*/
		void rotate(float angle, sf::Vector2f point);

		/**@brief
		* Metoda pozwalajaca skalowanie punktu
		*
		* @param factorX
		*	Wsp�czynnik skalowania wzgl�dem osi X
		*
		* @param factorY
		*	Wsp�czynnik skalowania wzgl�dem osi Y
		*
		*/
		void scale(float factorX, float factorY);


		Point2D& operator= (const Point2D& point);
		bool operator == (const Point2D& point);
};