#pragma once
#include <vector>
#include "DrawableObject.h"
#include "SpriteDirection.h"


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
	void manageCounter();
	void updatePosition(int x, int y, std::vector<sf::Sprite> &sprites);

public: 
	BitmapObject();
	BitmapObject(std::string filename);
	void loadSpritesFromFile(std::string filename);

	void draw(sf::RenderWindow* window);
	void changeToNextBitmap();
	void updateSpritesPosition(int x, int y);


};