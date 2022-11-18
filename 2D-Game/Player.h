#pragma once
#include "DrawableObject.h"

class Player: public virtual DrawableObject
{
private:
	static const int PLAYER_SPEED = 500;
	int x, y;
	sf::RectangleShape playerBox;

public:
	Player();
	Player(int x, int y);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	void update(float deltaTime);
	void move(float deltaTime);

	void draw(sf::RenderWindow* window);

	void updatePlayerBox();
};