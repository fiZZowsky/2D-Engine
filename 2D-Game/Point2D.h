#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"

class PrimitiveRenderer; // forward declaration

/**@brief
	* Klasa reprezentuj¹ca punkt
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
	* Metoda zwracaj¹ca pozycje X punktu
	*/
		int getX();

		/**@brief
		* Metoda zwracaj¹ca pozycje Y punktu
		*/
		int getY();

		/**@brief
		* Metoda ustawiaj¹ca pozycje X punktu
		*
		* @param x
		*	Nowa pozycja X
		*/
		void setX(int x);

		/**@brief
		* Metoda ustawiaj¹ca pozycje Y punktu
		*
		* @param y
		*	Nowa pozycja Y
		*/
		void setY(int y);

		/**@brief
		* Metoda zwracaj¹ca kolor punktu
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
		* Metoda ustawiajaca wspó³rzêdne odcinka
		*
		* @param x
		*	Wspó³rzêdna x
		* 
		* @param y
		*	Wspó³rzêdna y
		*	
		*/
		void setPoint(int x, int y);

		/**@brief
		* Metoda rysuj¹ca punkt
		*
		* @param window
		*	Okno, w którym ma byæ rysowany punkt
		*/
		void draw(sf::RenderWindow* window);

		/**@brief
		* Metoda pozwalajaca na przesuniêcie punktu o wektor
		*
		* @param offset
		*	Wektor przesuniêcia
		*/
		void translate(sf::Vector2f offset);

		/**@brief
		* Metoda pozwalajaca obrót punktu wokó³ punktu
		*
		* @param angle
		*	K¹t obrotu
		*
		* @param point
		*	Punkt, wzglêdem którego obracany jest punkt
		*/
		void rotate(float angle, sf::Vector2f point);

		/**@brief
		* Metoda pozwalajaca skalowanie punktu
		*
		* @param factorX
		*	Wspó³czynnik skalowania wzglêdem osi X
		*
		* @param factorY
		*	Wspó³czynnik skalowania wzglêdem osi Y
		*
		*/
		void scale(float factorX, float factorY);


		Point2D& operator= (const Point2D& point);
		bool operator == (const Point2D& point);
};