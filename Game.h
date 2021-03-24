#pragma once

#include "SDL.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "Constants.h"
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
	Wall *upper;
	Wall *lower;
	Wall *leftW;
	Wall *rightW;
	Paddle *left;
	Paddle *right;
	Ball* ball;

	void CreateScene();

	void Input(float deltaTime);
	void Update(float deltaTime) const;
	void Output(float deltaTime);
	void DrawBackground();
	void DrawObjects();
	void CheckCollisions(Entity *ent) const;
	void PaddleInput(const Uint8 *state, float deltaTime) const;
};