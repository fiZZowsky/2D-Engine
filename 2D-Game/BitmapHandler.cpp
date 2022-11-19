#include "BitmapHandler.h"

sf::Image BitmapHandler::create(unsigned int width, unsigned int height, const sf::Color color) {
	sf::Image bitmap;
	bitmap.create(width, height, color);
	return bitmap;
}