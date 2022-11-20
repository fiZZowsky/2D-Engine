#pragma once
#include <vector>
#include "DrawableObject.h"

class BitmapObject : public virtual DrawableObject
{
private:

	std::vector<sf::Image> bitmaps;
	std::vector<sf::Texture> textures;
	std::vector<sf::Sprite> sprites;

	int counter;

	void manageCounter();

public: 
	BitmapObject(sf::Image bitmap);
	BitmapObject(std::vector<sf::Image> bitmaps);


	void draw(sf::RenderWindow* window);
	void changeToNextBitmap();


};