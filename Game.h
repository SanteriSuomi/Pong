#pragma once

#include "SDL.h"
#include "Entity.h"
#include <memory>
#include <vector>

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();
private:
	SDL_Window *window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = false;
	std::unique_ptr<std::vector<std::unique_ptr<Entity>>> objects;

	void CreateScene() const;

	void Input();
	void Update();
	void Output();
	void DrawBackground();
	void DrawObjects();
};