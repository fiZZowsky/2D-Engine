#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
#include "Settings.h"

/**@brief
	* Klasa reprezentuj�ca obiekt, kt�ry mo�e by� rysowany przy pomocy sprite'�w i animowany
	*/
class SpriteObject : public virtual BitmapObject ,public virtual AnimatedObject
{

private:
	int framesCounter;

public:

	SpriteObject();
	SpriteObject(std::string filename);

	/**@brief
	* Metoda pozwalajaca na animowanie
	* 
	* @param window
	*	Okno, w kt�rym ma by� wy�wietlana animacja
	*/
	void animate(sf::RenderWindow* window);

};