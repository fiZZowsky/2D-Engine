#include "Engine.h"

const std::string Engine::PLAYER_SPRITESHEET = "Bitmaps/spritesheet.png";

Engine* Engine::instance = nullptr;




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
	player = Player(1400, 800, PLAYER_SPRITESHEET);
	doFillColor = false;
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

		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			this->window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.Event::key.code == Keyboard::Escape) {
				this->window->close();
			}

			break;
		case sf::Event::KeyReleased:
			if (event.Event::key.code == Keyboard::P) {
				if (doFillColor) doFillColor = false;
				else doFillColor = true;
			}
			break;

		default:
			break;
		}
	}
}

void Engine::render() {
	this->window->clear(sf::Color::White);

	player.drawPlayer(window);

	//=====================================================================================
	// Kod najduj¹cy siê poni¿ej s³u¿y do utworzenia dema technologicznego silnika
	// W metodzie render powinno znajdowaæ siê tylko rysowanie, lecz ze wzglêdu na chêæ
	// jak najmniejszej ingerencji w ca³¹ strukturê silnika prawie ca³y kod potrzebny 
	// do przedstawienia dema prezentuj¹cego mo¿liwoœci silnika zosta³ umieszczony 
	// w tej jednej metodzie
	//=====================================================================================
	sf::Font font;
	font.loadFromFile("arial.ttf");

	//=========================================
	// primitywy
	//=========================================
	sf::Text t1("Primitywy", font, 30);
	t1.setPosition(150, 30);
	t1.setFillColor(sf::Color::Black);
	window->draw(t1);

	window->draw(primitiveRenderer.drawRectangle(50, 150, 50, 50, sf::Color::Green, sf::Color::Blue));
	window->draw(primitiveRenderer.drawRectangle(150, 130, 150, 70, sf::Color::Green, sf::Color::Yellow));
	window->draw(primitiveRenderer.drawCircle(70, 220, 70, sf::Color::Green, sf::Color::Green));
	window->draw(primitiveRenderer.drawPolygon(250, 220, 50, 3, sf::Color::Green, sf::Color(255, 102, 0)));
	window->draw(primitiveRenderer.drawPolygon(250, 320, 40, 4, sf::Color::Green, sf::Color(255, 0, 102)));

	//=========================================
	// algorytm rysowowania ko³a i elipsy
	//=========================================

	sf::Text t2("Algorytm rysowania kola i elipsy", font, 30);
	t2.setPosition(700, 30);
	t2.setFillColor(sf::Color::Black);
	window->draw(t2);

	primitiveRenderer.myDrawCircle(window, 900, 150, 65, sf::Color(0, 102, 255));
	primitiveRenderer.myDrawElipse(window, 900, 300, 70, 40, sf::Color(0, 255, 0));


	//=========================================
	// Wypelnianie kolorem
	//=========================================

	Rectangle rec(1380, 230, 130, 120, sf::Color(102, 102, 102));
	rec.draw(window);

	sf::Text t3("Wypelnianie kolorem (nacisnij P)", font, 30);
	t3.setPosition(1400, 30);
	t3.setFillColor(sf::Color::Black);
	window->draw(t3);

	sf::Text boundryFillText("BoundryFill", font, 20);
	boundryFillText.setPosition(1400, 250);
	boundryFillText.setFillColor(sf::Color(255, 153, 51));
	window->draw(boundryFillText);

	sf::Text floodFillText("FloodFill", font, 20);
	floodFillText.setPosition(1400, 300);
	floodFillText.setFillColor(sf::Color(102, 255, 255));
	window->draw(floodFillText);


	Point2D p1(1500, 170), p2(1600, 190), p3(1800, 300), p4(1700, 350), p5(1650, 500);
	std::vector<Point2D> polyline;
	polyline.push_back(p1);
	polyline.push_back(p2);
	polyline.push_back(p3);
	polyline.push_back(p4);
	polyline.push_back(p5);

	LineSegment ls(&p1, &p4, sf::Color::Black);

	window->draw(primitiveRenderer.drawClosedPolyline(polyline, sf::Color::Black));
	ls.draw(window);

	if (doFillColor) {
		primitiveRenderer.boundryFill(window, Point2D(1600, 300), sf::Color(255, 153, 51), sf::Color::Black);
		primitiveRenderer.floodFill(window, Point2D(1550, 190), sf::Color(102, 255, 255));
	}


	//=========================================
	// Przekszta³cenia
	//=========================================

	sf::Text t4("Przeksztalcenia", font, 30);
	t4.setPosition(400, 600);
	t4.setFillColor(sf::Color::Black);
	window->draw(t4);

	Rectangle rec1(200, 700, 100, 100, sf::Color(51, 153, 255));
	Rectangle rec2(400, 700, 100, 100, sf::Color(51, 153, 255));
	Rectangle rec3(700, 700, 100, 100, sf::Color(51, 153, 255));
	rec1.draw(window);
	rec2.scale(2, 2);
	rec2.draw(window);
	rec3.rotate(30);
	rec3.draw(window);

	LineSegment segment1(200, 850, 200, 950);
	LineSegment segment2(200, 850, 200, 950);
	Point2D basePoint(250, 900, sf::Color(102, 0, 102));
	basePoint.draw(window);
	segment1.rotate(120, sf::Vector2f(basePoint.getX(), basePoint.getY()));

	window->draw(segment1.draw(sf::Color::Blue));
	window->draw(segment2.draw(sf::Color::Blue));


	//=========================================
	// Gracz
	//=========================================

	sf::Text t5("Gracz (Sterowanie strzalkami)", font, 30);
	t5.setPosition(1250, 600);
	t5.setFillColor(sf::Color::Black);
	window->draw(t5);


	this->window->display();
}