#include "BitmapHandler.h"

sf::Image BitmapHandler::create(unsigned int width, unsigned int height, const sf::Color color) {
	sf::Image bitmap;
	bitmap.create(width, height, color);
	return bitmap;
}

void BitmapHandler::remove(sf::Image* bitmap) {
	bitmap = new sf::Image();
}

bool BitmapHandler::loadFromFile(sf::Image *bitmap, std::string filename) {
	return bitmap -> loadFromFile(filename);
}

bool BitmapHandler::saveToFile(sf::Image bitmap, std::string filename) {
	return bitmap.saveToFile(filename);
}

void BitmapHandler::copy(sf::Image* src, sf::Image *dst) {
	dst->copy(*src, 0, 0);
}

void BitmapHandler::copy(sf::Image* src, sf::Image* dst, sf::IntRect rect) {
	dst->copy(*src, 0, 0, rect);
}

void BitmapHandler::flipHorizontally(sf::Image* bitmap) {
	bitmap->flipHorizontally();
}
void BitmapHandler::flipVertically(sf::Image* bitmap) {
	bitmap->flipVertically();
}