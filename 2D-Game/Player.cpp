#include "Player.h"

Player::Player() {
	this->x = 0;
	this->y = 0;
	isMoving = false;
}

Player::Player(int x, int y, std::string spritesheetFile): SpriteObject(spritesheetFile), BitmapObject(spritesheetFile) {
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
	updateSpritesPosition(x, y);
}

void Player::move(float deltaTime) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		isMoving = true;
		x += PLAYER_SPEED * deltaTime;
		currentlyUsedSprites = RIGHT;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		isMoving = true;
		x -= PLAYER_SPEED * deltaTime;
		currentlyUsedSprites = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		isMoving = true;
		y += PLAYER_SPEED * deltaTime;
		currentlyUsedSprites = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		isMoving = true;
		y -= PLAYER_SPEED * deltaTime;
		currentlyUsedSprites = UP;
	}

}

void Player::drawPlayer(sf::RenderWindow *window) {
	if (isMoving) {
		animate(window);
	}
	else {
		switch (currentlyUsedSprites) {
		case DOWN:
			window->draw(downSprites[0]);
			break;
		case LEFT:
			window->draw(leftSprites[0]);
			break;
		case RIGHT:
			window->draw(rightSprites[0]);
			break;
		case UP:
			window->draw(upSprites[0]);
			break;
		}
	
	}
}


