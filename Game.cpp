#include "Game.h"

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
	upper = new Wall(0, 0, WINDOW_WIDTH, WALL_THICKNESS, "WallUpper");
	lower = new Wall(0, WINDOW_HEIGHT - WALL_THICKNESS, WINDOW_WIDTH, WALL_THICKNESS, "WallLower");
	objects->emplace_back(upper);
	objects->emplace_back(lower);
	left = new Paddle(0, WINDOW_HEIGHT / 2 - (PADDLE_HEIGHT / 2), WALL_THICKNESS, PADDLE_HEIGHT, "PaddleLeft");
	right = new Paddle(WINDOW_WIDTH - WALL_THICKNESS, WINDOW_HEIGHT / 2 - (PADDLE_HEIGHT / 2), WALL_THICKNESS, PADDLE_HEIGHT, "PaddleRight");
	objects->emplace_back(left);
	objects->emplace_back(right);
	ball = new Ball(WINDOW_WIDTH / 2 - (WALL_THICKNESS / 2), WINDOW_HEIGHT / 2 - (WALL_THICKNESS / 2), WALL_THICKNESS, WALL_THICKNESS, 
		BALL_VEL_X, BALL_VEL_Y, "Ball");
	objects->emplace_back(ball);
}

void Game::Loop() {
	while (isRunning) {
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + FRAME_TIME));
		float deltaTime = (float)(SDL_GetTicks() - ticksCount) / 1000.0F;
		if (deltaTime > MAX_DELTA_TIME) {
			deltaTime = MAX_DELTA_TIME;
		}
		ticksCount = SDL_GetTicks();
		Input(deltaTime);
		Update(deltaTime);
		Output(deltaTime);
	}
}

void Game::Shutdown() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::Input(float deltaTime) {
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
	
	if (state[SDL_SCANCODE_W]) {
		//Vector2<float> pos {
		//	left->position->x,
		//	left->position->y
		//};
		//if (!upper->Collides(pos, *left->size)) {
		//	left->Move(0, -PADDLE_SPEED * deltaTime);
		//}
		// TO-DO improve 
		if (!left->Collides(upper)) {
			left->Move(0, -PADDLE_SPEED * deltaTime);
		}
	}
	if (state[SDL_SCANCODE_S]) {
		if (!left->Collides(lower)) {
			left->Move(0, PADDLE_SPEED * deltaTime);
		}
	}

	if (state[SDL_SCANCODE_O]) {
		right->Move(0, -PADDLE_SPEED * deltaTime);
	}
	if (state[SDL_SCANCODE_L]) {
		right->Move(0, PADDLE_SPEED * deltaTime);
	}
}

void Game::Update(float deltaTime) const {
	std::unordered_set<std::string> collided; // TO-DO: necessary?
	for (const auto &ent : *objects) {
		for (const auto &entColl : *objects) {
			if (ent != entColl 
				&& ent->Collides(entColl.get()) 
				&& (collided.count(ent->name) == 0 && collided.count(entColl->name) == 0)
				&& SDL_TICKS_PASSED(SDL_GetTicks(), ent->collisionTicks + COLLISION_WAIT_PERIOD)) {
				SDL_Log("Collision between: %s and %s", ent->name.c_str(), entColl->name.c_str());
				collided.insert(ent->name);
				collided.insert(entColl->name);
				ent->collision = entColl.get();
				ent->collisionTicks = SDL_GetTicks();
				break;
			}
		}
		ent->Update(deltaTime);
	}
}

void Game::Output(float deltaTime) {
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