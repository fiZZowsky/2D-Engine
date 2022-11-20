#include "BitmapObject.h"

void BitmapObject::manageCounter() {
	if (counter > sprites.size() - 1) {
		counter = 0;
	}
}

BitmapObject::BitmapObject() {};

BitmapObject::BitmapObject(sf::Image bitmap) {
	counter = 0;

	this->bitmaps.push_back(bitmap);

	sf::Texture texture;
	texture.loadFromImage(bitmap);
	this->textures.push_back(texture);

	sf::Sprite sprite(textures[0]);
	this->sprites.push_back(sprite);
}

BitmapObject::BitmapObject(std::vector<sf::Image> bitmaps) {
	counter = 0;

	this->bitmaps = bitmaps;

	for (int i = 0; i < bitmaps.size(); i++) {
		sf::Texture texture;
		texture.loadFromImage(bitmaps[i]);
		textures.push_back(texture);
	}


	for (int i = 0; i < textures.size(); i++) {
		sf::Sprite sprite(textures[i]);
		sprites.push_back(sprite);
	}

}

void BitmapObject::draw(sf::RenderWindow* window) {

	//TODO: delete this
	std::cout << counter << std::endl;

	//std::cout << sprites.size() << std::endl;
	window->draw(sprites[counter]);
}

void BitmapObject::changeToNextBitmap() {
	counter++;
	manageCounter();
}
