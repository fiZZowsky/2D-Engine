#include "SpritesManager.h"

SpritesManager::SpritesManager() { ; }


std::vector<sf::Sprite> SpritesManager::loadSpritesFromFile(std::string filename, int rows, int colums, int spritesInRow) {
	int width, height;
	sf::Vector2f spriteSize;


	if (spritesheet.loadFromFile(filename)) {
		width = spritesheet.getSize().x;
		height = spritesheet.getSize().y;
		spriteSize.x = width / spritesInRow;
		spriteSize.y = width / MAX_SPRITESHEET_ROWS_NUMBER;

		for (int i = 0; i < MAX_SPRITESHEET_ROWS_NUMBER; i++) {
			for (int j = 0; j < spritesInRow; j++) {

				//sf::IntRect(j * width, i * height, width, height)
				sf::Sprite sprite(spritesheet, sf::IntRect(j * spriteSize.x, i * spriteSize.y, spriteSize.x, spriteSize.y));
				spritesCollection.push_back(sprite);

			}
		}

	}

	return spritesCollection;
}
