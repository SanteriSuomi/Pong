#include "SDL.h"
#include "Game.h"

int main(int, char**) {
	Game game;
	if (game.Initialize()) {
		game.Loop();
	}
	game.Shutdown();
	return 0;
}