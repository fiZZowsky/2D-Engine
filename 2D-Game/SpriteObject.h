#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
#include "Settings.h"

/**@brief
	* Klasa reprezentuj¹ca obiekt, który mo¿e byæ rysowany przy pomocy sprite'ów i animowany
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
	*	Okno, w którym ma byæ wyœwietlana animacja
	*/
	void animate(sf::RenderWindow* window);

};