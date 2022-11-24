#include "BitmapObject.h"

void BitmapObject::manageCounter() {
	if (counter > COLUMNS_NUMBER - 1) {
		counter = 0;
	}
}

BitmapObject::BitmapObject() {
	counter = 0;
	currentlyUsedSprites = LEFT;
};

BitmapObject::BitmapObject(std::string filename) {
	counter = 0;
	currentlyUsedSprites = LEFT;

	loadSpritesFromFile(filename);
}
void BitmapObject::loadSpritesFromFile(std::string filename) {
	int width, height;
	sf::Vector2f spriteSize;

	bool isSpritesheetLoaded = false;

	//ading only one texture, whole sprite sheet
	sf::Texture spritesheetTexture;
	isSpritesheetLoaded = spritesheetTexture.loadFromFile(filename);
	

	if (isSpritesheetLoaded) {
		spritesheet.push_back(spritesheetTexture);
		width = spritesheet[0].getSize().x;
		height = spritesheet[0].getSize().y;
		spriteSize.x = width / ROWS_NUMBER;
		spriteSize.y = height / COLUMNS_NUMBER;

		for (int i = 0; i < ROWS_NUMBER; i++) {
			for (int j = 0; j < COLUMNS_NUMBER; j++) {

				//sf::IntRect(j * width, i * height, width, height)
				sf::Sprite sprite(spritesheet[0], sf::IntRect(j * spriteSize.x, i * spriteSize.y, spriteSize.x, spriteSize.y));

				//getting  down sprites
				if (i == DOWN) {
					std::cout << i << std::endl;
					downSprites.push_back(sprite);
				}
				else if (i == LEFT) {
					std::cout << i << std::endl;
					leftSprites.push_back(sprite);
				}
				else if (i == RIGHT) {
					rightSprites.push_back(sprite);
				}
				else if (i == UP) {
					upSprites.push_back(sprite);
				}
			}
		}

	}
}


void BitmapObject::draw(sf::RenderWindow* window) {

	switch (currentlyUsedSprites) {
	case DOWN:
		window->draw(downSprites[counter]);
		break;
	case LEFT:
		window->draw(leftSprites[counter]);
		break;
	case RIGHT:
		window->draw(rightSprites[counter]);
		break;
	case UP:
		window->draw(upSprites[counter]);
		break;
	}
}

void BitmapObject::changeToNextBitmap() {
	counter++;
	manageCounter();
}

void BitmapObject::updateSpritesPosition(int x, int y) {

	switch (currentlyUsedSprites) {
	case DOWN:
		updatePosition(x, y, downSprites);
		break;
	case LEFT:
		updatePosition(x, y, leftSprites);
		break;
	case RIGHT:
		updatePosition(x, y, rightSprites);
		break;
	case UP:
		updatePosition(x, y, upSprites);
		break;
	}

}

void BitmapObject::updatePosition(int x, int y, std::vector<sf::Sprite> &sprites) {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].setPosition(x, y);
	}
}
