#pragma once
#include "Headers.h"
#include "BitmapHandler.h"
#include "Settings.h"

class SpritesManager
{
private:
	sf::Texture spritesheet;
	std::vector<sf::Sprite> spritesCollection;

public:
	SpritesManager();
	std::vector<sf::Sprite> loadSpritesFromFile(std::string filename, int rows, int colums, int spritesInRow);

};
