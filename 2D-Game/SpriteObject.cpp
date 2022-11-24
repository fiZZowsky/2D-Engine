#include "SpriteObject.h"

SpriteObject::SpriteObject() {
	framesCounter = 0;
}

SpriteObject::SpriteObject(std::string filename): BitmapObject(filename) {
	framesCounter = 0;
}

void SpriteObject::animate(sf::RenderWindow *window) {
	draw(window);

	framesCounter++;

	if (framesCounter >= (FPS_LIMIT / FRAMES_SPEED)) {
		framesCounter = 0;
		changeToNextBitmap();
	}
}
