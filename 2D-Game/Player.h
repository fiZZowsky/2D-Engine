#pragma once
#include "SpriteObject.h"
#include "UpdatableObject.h"

/**@brief
	* Klasa reprezentująca gracza
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
	* Metoda zwracająca pozycje X gracza
	*/
	int getX();

	/**@brief
	* Metoda zwracająca pozycje Y gracza
	*/
	int getY();

	/**@brief
	* Metoda ustawiająca pozycje X gracza
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiająca pozycje Y gracza
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);

	/**@brief
	* Metoda aktualizująca gracza
	*
	* @param deltaTime
	*	Czas pomiędzy klatkami
	*/
	void update(float deltaTime);

	/**@brief
	* Metoda pozwalająca na poruszanie się gracza
	*
	* @param deltaTime
	*	Czas pomiędzy klatkami
	*/
	void move(float deltaTime);

	/**@brief
	* Metoda pozwalająca na rysowanie gracza
	*
	* @param window
	*	Okno, w którym ma być rysowany gracz
	*/
	void drawPlayer(sf::RenderWindow *window);

};