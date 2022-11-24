#pragma once
#include "Headers.h"
#include "BitmapHandler.h"
#include "Settings.h"

enum SpritesDirection{ DOWN, LEFT, RIGHT, UP};

class SpritesManager
{
private:
	static const int ROWS_NUMBER = 4;
	static const int COLUMNS_NUMBER = 4;


	sf::Texture spritesheet;
	std::vector<sf::Sprite> leftSprites;
	std::vector<sf::Sprite> rightSprites;
	std::vector<sf::Sprite> upSprites;
	std::vector<sf::Sprite> downSprites;

public:
	SpritesManager();
	SpritesManager(std::string filename);
	void loadSpritesFromFile(std::string filename);

	std::vector<sf::Sprite> getLeftSprites();
	std::vector<sf::Sprite> getRightSprites();
	std::vector<sf::Sprite> getUpSprites();
	std::vector<sf::Sprite> getDownSprites();


};
