#include "Engine.h"

void Engine::input() {
	if (Keyboard::isKeyPressed(Keyboard::Escape)) 
		m_window.close();
	/*if (Keyboard::isKeyPressed(Keyboard::A))
		m_character.moveLeft();
	else
		m_character.stopLeft();
	if (Keyboard::isKeyPressed(Keyboard::D))
		m_character.moveRight();
	else
		m_character.stopRight();	
	if (Keyboard::isKeyPressed(Keyboard::Space))
		m_character.jump();
	else
		m_character.fall();
		*/
}