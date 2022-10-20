#include "Engine.h"

using namespace sf;

void Engine::draw() {
	m_window.clear(Color::White);
	//m_window.draw(m_character.getSprite());
	m_window.display();
}