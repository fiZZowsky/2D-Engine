#include "Engine.h"

Engine* Engine::instance = nullptr;
const std::string Engine::PLAYER_SPRITESHEET = "Bitmaps/spritesheet.png";


Engine::Engine() {
	this->init(WINDOWED);
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

		curTime = clock.getElapsedTime();
		this->deltaTime = curTime.asSeconds() - prevTime.asSeconds();
	}
}

void Engine::initGame() {
	player = Player(0, 0, PLAYER_SPRITESHEET);
}

//Private functions
void Engine::init(int windowMode) {
	Vector2f resolution;

	initGame();

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
	this->window->setFramerateLimit(FPS_LIMIT);
}

void Engine::update() {
	Event event;

	player.update(deltaTime);

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
	
	player.drawPlayer(window);

	//sf::Texture t;
	//t = player.spritesheet[0];
	//sf::Sprite s(t);
	////window->draw(s);
	//window->draw(player.upSprites[1]);


	// sf::Sprite sprite(player.spritesheet);
	//sf::Sprite sprite2(player.spritesheet, sf::IntRect(0, 0, 64, 64));
	//window->draw(sprite);
	//player.loadSpritesFromFile("Bitmaps/spritesheet.png");

	//for (int i = 0; i < player.allSprites.size(); i++) {
	//	window->draw(player.allSprites[i]);
	//}




	/*sf::Image image, im2;
	image.loadFromFile("Bitmaps/p1.png");
	im2.loadFromFile("Bitmaps/t1.png");

	std::vector<sf::Image> bitmaps;
	bitmaps.push_back(image);
	bitmaps.push_back(im2);

	BitmapObject bo(bitmaps);
	bo.changeToNextBitmap();
	bo.changeToNextBitmap();
	bo.draw(window);*/

	//sf::Texture texture;
	//texture.loadFromImage(image);
	//sf::Sprite sprite(texture);

	////window->draw(sprite);

	//BitmapObject bo(image);
	////sf::Texture tx1;
	////tx1.loadFromImage(bo.bitmaps[0]);
	////sf::Sprite sp1(bo.textures[0]);
	////window->draw(sp1);

	////SpriteObject tmp(image);



	//player.update(deltaTime);
	////Player p1(200, 200);
	////p1.draw(window);
	//player.draw(window);

	//BitmapHandler bh;
	//sf::Texture texture;
	// 
	


	//sf::Image bitmap = bh.create(300, 300, sf::Color::Blue);
	/*sf::Image bitmap, t1, t2;
	bh.loadFromFile(&bitmap, "Bitmaps/bitmap-test.png");
	bh.flipHorizontally(&bitmap);
	bh.saveToFile(bitmap, "Bitmaps/bitmap-saved.png");

	bh.loadFromFile(&t1, "t1.png");
	bh.loadFromFile(&t2, "t2.png");

	bh.remove(&t2);



	bh.copy(&t1, &bitmap);

	texture.loadFromImage(bitmap);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	window->draw(sprite);*/


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