#include "BitmapHandler.h"

sf::Image BitmapHandler::create(unsigned int width, unsigned int height, const sf::Color color) {
	sf::Image bitmap;
	bitmap.create(width, height, color);
	return bitmap;
}

bool BitmapHandler::loadFromFile(sf::Image *bitmap, std::string filename) {
	return bitmap -> loadFromFile(filename);
}

bool BitmapHandler::saveToFile(sf::Image bitmap, std::string filename) {
	return bitmap.saveToFile(filename);
}