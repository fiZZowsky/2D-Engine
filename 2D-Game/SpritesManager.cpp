#include "SpritesManager.h"

SpritesManager::SpritesManager() { ; }

SpritesManager::SpritesManager(std::string filename) {
	loadSpritesFromFile(filename);
}


void SpritesManager::loadSpritesFromFile(std::string filename) {
	int width, height;
	sf::Vector2f spriteSize;


	if (spritesheet.loadFromFile(filename)) {
		width = spritesheet.getSize().x;
		height = spritesheet.getSize().y;
		spriteSize.x = width / ROWS_NUMBER;
		spriteSize.y = height / COLUMNS_NUMBER;

		for (int i = 0; i < ROWS_NUMBER; i++) {
			for (int j = 0; j < COLUMNS_NUMBER; j++) {

				//sf::IntRect(j * width, i * height, width, height)
				sf::Sprite sprite(spritesheet, sf::IntRect(j * spriteSize.x, i * spriteSize.y, spriteSize.x, spriteSize.y));

				//getting  downs sprites
				if (i == DOWN) {
					downSprites.push_back(sprite);
				}
				else if (i == LEFT) {
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

std::vector<sf::Sprite> SpritesManager::getLeftSprites() {
	return leftSprites;
}
std::vector<sf::Sprite> SpritesManager::getRightSprites() {
	return rightSprites;
}
std::vector<sf::Sprite> SpritesManager::getUpSprites() {
	return upSprites;
}
std::vector<sf::Sprite> SpritesManager::getDownSprites() {
	return downSprites;
}
