#include "character.h"

character::character() {
	m_Position.x = 500.0f;
	m_Position.y = 500.0f;
	m_Speed.x = 0;
	m_Speed.y = 0;
	//forward = true;
	goesLeft = false;
	goesRight = false;

	m_Texture.loadFromFile("character.png");
	player.setTexture(m_Texture);
	player.setPosition(m_Position);
}

character::~character() {}

Sprite character::getSprite() {
	return player;
}


void character::move(float elapsedTime) {
	//m_prevPosition = m_Position;
	m_Position.x += m_Speed.x * elapsedTime;
	if (m_Position.x < 51 / 2) {
		m_Position.x = 51 / 2;
		m_Speed.x = 0;
	}
	if (m_Position.x > 1920 - 51 / 2) {
		m_Position.x > 1920 - 51 / 2;
		m_Speed.x = 0;
	}
	if (goesLeft) {
		m_Speed.x -= 1500 * elapsedTime;
		if (m_Speed.x < -300)
			m_Speed.x = -300;
	}
	if (goesRight) {
		m_Speed.x += 1500 * elapsedTime;
		if (m_Speed.x > 300)
			m_Speed.x = 300;
	}
	if (!goesLeft && !goesRight) {
		if (m_Speed.y == 0) {
			if (m_Speed.x > 0) {
				m_Speed.x -= 1500 * elapsedTime;
				if (m_Speed.x < 10)
					m_Speed.x = 0;
			}
			if (m_Speed.x < 0) {
				m_Speed.x += 1500 * elapsedTime;
				if (m_Speed.x > -10)
					m_Speed.x = 0;
			}
		}
	}
	
	m_Position.y += m_Speed.y * elapsedTime;
	m_Speed.y += 1500 * elapsedTime;

	player.setPosition(m_Position);
}

void character::jump(bool fullJump) {
	if (fullJump)
		m_Speed.y = -700;
	else
		m_Speed.y = -400;

	player.setPosition(m_Position);
}

void character::stopFalling() {
	m_Speed.y = 0;
	m_Position.y = 700;
}
