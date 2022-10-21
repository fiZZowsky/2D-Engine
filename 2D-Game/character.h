#pragma once
#include "frameworks.h"

using namespace sf;

class character {
private:
	Vector2f m_Speed;
	Texture m_Texture;

	//bool forward;
public:
	character();
	~character();

	Vector2f m_Position;
	Sprite player;
	//Vector2f m_prevPosition;

	bool goesLeft;
	bool goesRight;

	Sprite getSprite();

	void move(float elapsedTime);
	void jump(bool fullJump);
	void stopFalling();
};
