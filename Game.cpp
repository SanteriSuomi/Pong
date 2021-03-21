#include "Game.h"
#include "Paddle.h"
#include <memory>
#include "Wall.h"
#include "Constants.h"

bool Game::Initialize() {
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (result == 0) {
		window = SDL_CreateWindow(
			"Pong",
			300,
			175,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			0
		);
		if (!window) {
			SDL_Log("Failed to create window: %s", SDL_GetError());
			return false;
		}
		renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
		if (!renderer) {
			SDL_Log("Failed to create renderer: %s", SDL_GetError());
			return false;
		}
		isRunning = true;
		objects = std::make_unique<std::vector<std::unique_ptr<Entity>>>();
		CreateScene();
		return true;
	}
	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
	return false;
}

void Game::CreateScene() {
	objects->emplace_back(std::make_unique<Wall>(Wall(0, 0, WINDOW_WIDTH, WALL_THICKNESS)));
	objects->emplace_back(std::make_unique<Wall>(Wall(0, WINDOW_HEIGHT - WALL_THICKNESS, WINDOW_WIDTH, WALL_THICKNESS)));
	left = new Paddle(0, WINDOW_HEIGHT / 2 - (PADDLE_HEIGHT / 2), WALL_THICKNESS, PADDLE_HEIGHT);
	right = new Paddle(WINDOW_WIDTH - WALL_THICKNESS, WINDOW_HEIGHT / 2 - (PADDLE_HEIGHT / 2), WALL_THICKNESS, PADDLE_HEIGHT);
	objects->emplace_back(left);
	objects->emplace_back(right);
	ball = new Ball(WINDOW_WIDTH / 2 - (WALL_THICKNESS / 2), WINDOW_HEIGHT / 2 - (WALL_THICKNESS / 2), WALL_THICKNESS, WALL_THICKNESS, BALL_VEL_X, BALL_VEL_Y);
	objects->emplace_back(ball);
}

void Game::Loop() {
	while (isRunning) {
		Input();
		Update();
		Output();
	}
}

void Game::Shutdown() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::Input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			default:
				break;
		}
	}
	auto state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
}

void Game::Update() {
	for (const auto& ent : *objects) {
		ent->Update();
	}
}

void Game::Output() {
	DrawBackground();
	DrawObjects();
	SDL_RenderPresent(renderer);
}

void Game::DrawBackground() {
	SDL_SetRenderDrawColor(
		renderer,
		105,
		162,
		255,
		255
	);
	SDL_RenderClear(renderer);
}

void Game::DrawObjects() {
	SDL_SetRenderDrawColor(
		renderer,
		0,
		0,
		0,
		255
	);
	for (const auto &ent : *objects) {
		ent->Draw(renderer);
	}
}