#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include "Settings.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Player.h"
#include "BitmapHandler.h"
#include "BitmapObject.h"
#include "SpriteObject.h"

using namespace sf;

/**@brief
* Typ wyliczeniowy okreœlaj¹cy sposoby otwierania okna
*/
enum WindowMode {FULLSCREEN, WINDOWED, CUSTOM};

/**@brief
* G³ówna klasa silnika
*/
class Engine {

	static const std::string PLAYER_SPRITESHEET;

private:
	static Engine* instance;
	Engine();
	virtual ~Engine();

	sf::Clock clock;
	float deltaTime;

	/**@brief
	* Metoda odpowiedzialna za inicjacje silnika
	*/
	void init(int windowMode);

	/**@brief
	* Metoda odpowiedzialna za aktualizacje w silniku
	*/
	void update();

	/**@brief
	* Metoda odpowiedzialna za rysowanie
	*/
	void render();

	PrimitiveRenderer primitiveRenderer;
	Player player;

public:
	/**@brief
	* Metoda zwracaj¹ca jedyny obiekt silnika
	*/
	static Engine *getInstance();

	sf::RenderWindow* window;

	bool doFillColor;

	/**@brief
	* Metoda opakowuj¹ca g³ówn¹ pêtle gry
	*/
	void run();

	/**@brief
	* Metoda zwracaj¹ca czas pomiêdzy klatkami 
	*/
	float getDeltaTime();

	/**@brief
	* Metoda inicjujaca obiekty gry
	*/
	void initGame();
};