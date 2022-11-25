#pragma once
#include "SpriteObject.h"
#include "UpdatableObject.h"

/**@brief
	* Klasa reprezentuj�ca gracza
*/
class Player: public virtual SpriteObject, public virtual UpdatableObject
{
private:
	static const int PLAYER_SPEED = 400;
	int x, y;
	int isMoving;

public:
	Player();
	Player(int x, int y, std::string spritesheetFile);

	/**@brief
	* Metoda zwracaj�ca pozycje X gracza
	*/
	int getX();

	/**@brief
	* Metoda zwracaj�ca pozycje Y gracza
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj�ca pozycje X gracza
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj�ca pozycje Y gracza
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);

	/**@brief
	* Metoda aktualizuj�ca gracza
	*
	* @param deltaTime
	*	Czas pomi�dzy klatkami
	*/
	void update(float deltaTime);

	/**@brief
	* Metoda pozwalaj�ca na poruszanie si� gracza
	*
	* @param deltaTime
	*	Czas pomi�dzy klatkami
	*/
	void move(float deltaTime);

	/**@brief
	* Metoda pozwalaj�ca na rysowanie gracza
	*
	* @param window
	*	Okno, w kt�rym ma by� rysowany gracz
	*/
	void drawPlayer(sf::RenderWindow *window);

};