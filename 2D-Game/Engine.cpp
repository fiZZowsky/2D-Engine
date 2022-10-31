#include "Engine.h"

Engine::Engine() {
	this->initWindow(WINDOWED);
	this->initPlayer();
}

Engine::~Engine(){
	delete this->window;
	delete this->player;
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
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Platform Game", Style::Fullscreen);
		break;
	case WINDOWED:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Platform Game", Style::Close);
		break;
	case CUSTOM:
		this->window = new RenderWindow(VideoMode(CUSTOM_RESOLUTION_X, CUSTOM_RESOLUTION_Y), "2D Platform Game", Style::Close);
		break;
	}

	this->window->setVerticalSyncEnabled(true);
}

void Engine::initPlayer(){
	this->player = new Player();
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

	//Move player
	this->player->control();
}

void Engine::render() {
	this->window->clear(sf::Color::White);

	//Draw all the stuffs
	window->draw(primitiveRenderer.drawRectangle(80, 400, 200, 50));
	window->draw(primitiveRenderer.drawCircle(300, 300, 40));
	window->draw(primitiveRenderer.drawTriangle(50, 50, 30));
	window->draw(primitiveRenderer.drawSFMLLine(500, 500, 150, 45));
	/*window->draw(primitiveRenderer.drawLine(0, 2, 10, 4));*/

	this->player->render(*this->window);
	this->window->display();
}
