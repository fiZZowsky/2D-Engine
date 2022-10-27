#pragma once

#include "Headers.h"

class Player {
public:
	Player();
	virtual ~Player();

	//Functions
	void move(const float dirX, const float dirY);
	void control();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	//Private functions
	void initTexture();
	void initSprite();
};