#pragma once

#include "SDL.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
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
	Uint32 ticksCount;
	std::unique_ptr<std::vector<std::unique_ptr<Entity>>> objects;
	Paddle *left;
	Paddle *right;
	Ball* ball;

	void CreateScene();

	void Input(float deltaTime);
	void Update(float deltaTime);
	void Output(float deltaTime);
	void DrawBackground();
	void DrawObjects();
};