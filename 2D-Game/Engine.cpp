#include "Engine.h"

Engine::Engine() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_window.create(VideoMode(resolution.x, resolution.y), "2D Platform Game", Style::Fullscreen);
}

void Engine::start() {
	Clock clock;

	while (m_window.isOpen()) {
		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input();
		collision();
		update(dtAsSeconds);
		draw();
	}
}