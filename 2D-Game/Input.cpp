#include "Engine.h"

void Engine::input() {
	bool leftPressed = false;
	bool rightPressed = false;
	bool spacePressed = false;

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		m_window.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		leftPressed = true;
		character.goesLeft = leftPressed;
	} else {
		leftPressed = false;
		character.goesLeft = leftPressed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		rightPressed = true;
		character.goesRight = rightPressed;
	} else {
		rightPressed = false;
		character.goesRight = rightPressed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		spacePressed = true;
		character.jump(true);
	} else {
		spacePressed = false;
	}
}