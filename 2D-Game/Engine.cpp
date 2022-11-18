#include "Engine.h"

Engine::Engine() {
	this->initWindow(WINDOWED);
}

Engine::~Engine() {
	delete this->window;
}

//Functions
void Engine::run() {
	int fps;
	clock = sf::Clock::Clock();
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time curTime;

	// Main Loop
	while (this->window->isOpen()) {
		this->update();
		this->render();

		//FPS counter
		curTime = clock.getElapsedTime();
		fps = 1.0f / (curTime.asSeconds() - prevTime.asSeconds());
		/*std::cout << fps << std::endl;*/
		prevTime = curTime;
	}
}


//Private functions
void Engine::initWindow(int windowMode) {
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	switch (windowMode) {
	case FULLSCREEN:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Game Engine", Style::Fullscreen);
		break;
	case WINDOWED:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Game Engine", Style::Close);
		break;
	case CUSTOM:
		this->window = new RenderWindow(VideoMode(SCREEN_WIDTH_FHD, SCREEN_HEIGHT_FHD), "2D Game Engine", Style::Close);
		break;
	}

	this->window->setVerticalSyncEnabled(true);
}

void Engine::update() {
	Event event;

	while (this->window->pollEvent(event)) {
		if (event.Event::type == Event::Closed) {
			this->window->close();
		}
		if (event.Event::KeyPressed && event.Event::key.code == Keyboard::Escape) {
			this->window->close();
		}
	}
}

void Engine::render() {
	this->window->clear(sf::Color::White);


	Triangle t1(100, 100, 30, sf::Color::Green);
	t1.rotate(15);
	t1.setX(500);
	t1.draw(window);

	Polygon p1(300, 300, 7, 50, sf::Color::Yellow);
	p1.rotate(15);
	p1.draw(window);


	//============================================================================================

	this->window->display();
}