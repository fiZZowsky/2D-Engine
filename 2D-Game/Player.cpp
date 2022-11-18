#include "Player.h"

Player::Player() {
	this->x = 200;
	this->y = 200;
	playerBox.setFillColor(sf::Color::Blue);
	playerBox.setSize(sf::Vector2f(50, 50));
	updatePlayerBox();
}

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
	playerBox.setFillColor(sf::Color::Blue);
	playerBox.setSize(sf::Vector2f(50, 50));
	updatePlayerBox();
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::setX(int x) {
	this->x = x;
	updatePlayerBox();
}

void Player::setY(int y) {
	this->y = y;
	updatePlayerBox();
}

void Player::update(float deltaTime) {
	move(deltaTime);
}

void Player::move(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		x += PLAYER_SPEED * deltaTime;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		x -= PLAYER_SPEED * deltaTime;
	}

	updatePlayerBox();
}

void Player::draw(sf::RenderWindow* window) {
	window->draw(playerBox);
}


void Player::updatePlayerBox() {
	playerBox.setPosition(this->x, this->y);
}

