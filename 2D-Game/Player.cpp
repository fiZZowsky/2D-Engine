#include "Player.h"

Player::Player(){
	this->movementSpeed = 1.f;

	this->initTexture();
	this->initSprite();
}

Player::~Player() {

}

void Player::move(const float dirX, const float dirY) {
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->sprite.setScale(-1.f, 1.f);
		move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->sprite.setScale(1.f, 1.f);
		move(1.f, 0.f);
	}
}

//Functions
void Player::update() {
}

void Player::initTexture() {
	//Load texture from file
	if (!this->texture.loadFromFile("./Textures/character.png")) {
		std::cout << "ERROR::PLAYER::LOAD_TEXTURE::Could not find the texture file!" << std::endl;
	}
}

void Player::initSprite() {
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(1.f, 1.f);
}

void Player::render(sf::RenderTarget& target) {
	target.draw(this->sprite);
}