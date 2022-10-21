#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds) {
	character.move(dtAsSeconds);
}