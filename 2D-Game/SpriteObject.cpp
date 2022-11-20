#include "SpriteObject.h"

SpriteObject::SpriteObject() {
	framesCounter = 0;
}

SpriteObject::SpriteObject(sf::Image image): BitmapObject(image) {
	framesCounter = 0;
}

SpriteObject::SpriteObject(std::vector<sf::Image> bitmaps): BitmapObject(bitmaps) {
	framesCounter = 0;
}

void SpriteObject::animate(sf::RenderWindow *window) {
	draw(window);

	framesCounter++;

	std::cout << "framesCounter: " << framesCounter << std::endl;
	if (framesCounter >= (FPS_LIMIT / FRAMES_SPEED)) {
		framesCounter = 0;
		changeToNextBitmap();
	}
}
