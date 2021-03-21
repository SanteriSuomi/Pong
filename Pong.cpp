#include "SDL.h"
#include "Game.h"

int main(int argc, char** args) {
	Game game;
	if (game.Initialize()) {
		game.Loop();
	}
	game.Shutdown();
	return 0;
}