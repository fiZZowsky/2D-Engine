#include "Player.h"

Player::Player() {
	this->x = 0;
	this->y = 0;
	isMoving = false;
}

Player::Player(int x, int y, std::vector<sf::Image> bitmaps): SpriteObject(bitmaps), BitmapObject(bitmaps) {
	this->x = x;
	this->y = y;
	isMoving = false;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::setX(int x) {
	this->x = x;
}

void Player::setY(int y) {
	this->y = y;
}

void Player::update(float deltaTime) {
	isMoving = false;
	move(deltaTime);
}

void Player::move(float deltaTime) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		isMoving = true;
		x += PLAYER_SPEED * deltaTime;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		isMoving = true;
		x -= PLAYER_SPEED * deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		isMoving = true;
		//std::cout << " tutaj" << std::endl;
		y += PLAYER_SPEED * deltaTime;
		updateSpritesPosition(x, y);
	}
}

void Player::drawPlayer(sf::RenderWindow *window) {
	if (isMoving) {
		animate(window);
	}
	else {
		window->draw(sprites[0]);
	}
}


