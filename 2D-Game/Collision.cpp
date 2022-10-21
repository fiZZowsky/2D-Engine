#include "Engine.h"

void Engine::collision() {
	if (character.m_Position.y > 700)
		character.stopFalling();
}