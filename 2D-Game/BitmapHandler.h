#pragma once
#include "Headers.h"


class BitmapHandler
{
public:
	sf::Image create(unsigned int width, unsigned int height, const sf::Color color = sf::Color(0, 0, 0));
	bool loadFromFile(sf::Image *bitmap, std::string filename);
	bool saveToFile(sf::Image bitmap, std::string filename);
	void copy();
	void flipHorizontally();
	void flipVertically();

};