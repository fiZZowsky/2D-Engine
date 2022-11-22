#pragma once
#include "Headers.h"


class BitmapHandler
{
public:
	sf::Image create(unsigned int width, unsigned int height, const sf::Color color = sf::Color(0, 0, 0));
	void remove(sf::Image* bitmap);
	bool loadFromFile(sf::Image *bitmap, std::string filename);
	bool saveToFile(sf::Image bitmap, std::string filename);
	void copy(sf::Image* src, sf::Image *dst);
	void copy(sf::Image* src, sf::Image* dst, sf::IntRect rect);
	void flipHorizontally(sf::Image* bitmap);
	void flipVertically(sf::Image* bitmap);
};