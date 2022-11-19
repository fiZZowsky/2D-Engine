#include "Engine.h"

int main() {
	Engine *engine = Engine::getInstance();

	engine -> run();

	//End of application
	return 0;
}