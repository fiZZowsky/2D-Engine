#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine() {
	this->initWindow(WINDOWED);
}

Engine::~Engine() {
	delete this->window;
}

Engine* Engine::getInstance() {
	if ( instance == nullptr) {
		instance = new Engine();
	}
	return instance;
}


void Engine::run() {
	clock = sf::Clock::Clock();
	sf::Time prevTime;
	sf::Time curTime;

	// Main Loop
	while (this->window->isOpen()) {
		prevTime = clock.getElapsedTime();;

		this->update();
		this->render();

		//FPS counter
		curTime = clock.getElapsedTime();
		this->deltaTime = curTime.asSeconds() - prevTime.asSeconds();
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

	player.update(deltaTime);
	//Player p1(200, 200);
	//p1.draw(window);
	player.draw(window);


	//Point2D p1(100, 100), p2(200, 100), p3(200, 300);
	//std::vector<Point2D> points;
	//points.push_back(p1);
	//points.push_back(p2);
	//points.push_back(p3);

	//primitiveRenderer.myDrawPolygon(window, points, sf::Color::Black);
	//primitiveRenderer.floodFill(window, Point2D(150, 150), sf::Color::Yellow);
	////primitiveRenderer.boundryFill(window, Point2D(150, 150), sf::Color::Blue, sf::Color::Black);
	//primitiveRenderer.myDrawCircle(window, 500, 500, 50, sf::Color::Blue);
	//primitiveRenderer.myDrawElipse(window, 600, 500, 50, 30, sf::Color::Green);


	/*Triangle t1(100, 100, 30, sf::Color::Green);
	t1.rotate(15);
	t1.setX(500);
	t1.draw(window);

	Polygon p1(300, 300, 7, 50, sf::Color::Yellow);
	p1.rotate(15);
	p1.draw(window);

	LineSegment(10, 10, 50, 50);*/

	/*Point2D p1(50, 50, sf::Color::Blue), p2(50, 100);
	sf::Vector2f point(50, 100);

	p2.draw(window);
	p1.rotate(90, point);
	p1.draw(window);*/

	//LineSegment ls1(300, 100, 300, 300, sf::Color::Red), ls2(300, 100, 300, 300, sf::Color::Blue);
	//Point2D point(250, 200);
	//sf::Vector2f x0(250, 200);
	//point.draw(window);
	////ls1.scale(3, x0);
	//ls1.rotate(90, x0);
	//ls1.draw(window);
	//ls2.draw(window);

	//LineSegment ls1(300, 100, 300, 300, sf::Color::Red);
	//ls1.translate(sf::Vector2f(400, 400));
	//ls1.draw(window);
	





	//============================================================================================

	this->window->display();
}