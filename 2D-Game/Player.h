#pragma once
#include "SpriteObject.h"
#include "UpdatableObject.h"

/**@brief
	* Klasa reprezentuj¹ca gracza
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
	* Metoda zwracaj¹ca pozycje X gracza
	*/
	int getX();

	/**@brief
	* Metoda zwracaj¹ca pozycje Y gracza
	*/
	int getY();

	/**@brief
	* Metoda ustawiaj¹ca pozycje X gracza
	*
	* @param x
	*	Nowa pozycja X
	*/
	void setX(int x);

	/**@brief
	* Metoda ustawiaj¹ca pozycje Y gracza
	*
	* @param y
	*	Nowa pozycja Y
	*/
	void setY(int y);

	/**@brief
	* Metoda aktualizuj¹ca gracza
	*
	* @param deltaTime
	*	Czas pomiêdzy klatkami
	*/
	void update(float deltaTime);

	/**@brief
	* Metoda pozwalaj¹ca na poruszanie siê gracza
	*
	* @param deltaTime
	*	Czas pomiêdzy klatkami
	*/
	void move(float deltaTime);

	/**@brief
	* Metoda pozwalaj¹ca na rysowanie gracza
	*
	* @param window
	*	Okno, w którym ma byæ rysowany gracz
	*/
	void drawPlayer(sf::RenderWindow *window);

};