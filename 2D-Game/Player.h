#pragma once
#include "SpriteObject.h"

class Player: public virtual SpriteObject
{
private:
	static const int PLAYER_SPEED = 400;
	int x, y;
	int isMoving;

public:
	Player();
	Player(int x, int y, std::string spritesheetFile);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	void update(float deltaTime);
	void move(float deltaTime);
	void drawPlayer(sf::RenderWindow *window);

};