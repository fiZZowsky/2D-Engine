#pragma once
#include <vector>
#include "DrawableObject.h"
#include "SpriteDirection.h"

/**@brief
	* Klasa bazowa dla obiektow, kt�re mog� by� rysowane z wykorzystaniem bitmap
	*/
class BitmapObject : public virtual DrawableObject
{
protected:
	static const int ROWS_NUMBER = 4;
	static const int COLUMNS_NUMBER = 4;

	std::vector<sf::Texture> spritesheet;
	std::vector<sf::Sprite> leftSprites;
	std::vector<sf::Sprite> rightSprites;
	std::vector<sf::Sprite> upSprites;
	std::vector<sf::Sprite> downSprites;

	int currentlyUsedSprites;
	int counter;

	/**@brief
	* Metoda zarz�dzaj�ca licznikiem animacj
	*/
	void manageCounter();

	/**@brief
	* Metoda pomocnicza aktualizuj�ca pozycje element�w zbiorow sprite'ow, z kt�rych sk�ada sie obiekt
	*/
	void updatePosition(int x, int y, std::vector<sf::Sprite> &sprites);

public: 

	BitmapObject();
	BitmapObject(std::string filename);

	/**@brief
	* Metoda wczytuj�ca sprite'y z pliku
	*/
	void loadSpritesFromFile(std::string filename);

	/**@brief
	* Metoda pozwalajaca na rysowanie obiektu
	*/
	void draw(sf::RenderWindow* window);

	/**@brief
	* Metoda zmieniaj�ca kolejna klatk� animacji
	*/
	void changeToNextBitmap();

	/**@brief
	* Metoda aktualizuj�ca pozycje element�w zbiorow sprite'ow, z kt�rych sk�ada sie obiekt
	*/
	void updateSpritesPosition(int x, int y);


};