#include "Engine.h"

Engine::Engine() {
	this->initWindow();
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
void Engine::initWindow() {
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Platform Game", Style::Close);
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
	window->draw(primitiveRender.circle);
	window->draw(primitiveRender.rectangle);
	/*window->draw(primitiveRender.triangle);*/
	/*window->draw(primitiveRender.drawLine(0, 2, 10, 4));*/

	this->player->render(*this->window);
	this->window->display();
}
