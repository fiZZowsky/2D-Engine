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
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}	
}


//Private functions
void Engine::initWindow() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Platform Game", Style::Close);
	this->window->setVerticalSyncEnabled(false);
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
	this->player->render(*this->window);
	this->window->display();
}
