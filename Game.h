#pragma once

#include "SDL.h"

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();
private:
	SDL_Window *window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = false;
	void Input();
	void Update();
	void Output();
};