#pragma once

#include "SDL.h";

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();
private:
	SDL_Window* window = nullptr;
	bool isRunning = false;
	void Input();
	void Update();
	void Output();
};