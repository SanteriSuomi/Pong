#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, float velX, float velY, const std::string &name) 
	: Entity::Entity(x, y, width, height, name) {
	velocity = std::make_unique<Vector2<float>>(Vector2<float> {
		velX,
		velY
		});
}

void Ball::Update(float deltaTime) {
	if (collision) {
		if (collision->name == "WallUpper" || collision->name == "WallLower") {
			velocity->y *= -1;
		} else if (collision->name == "PaddleLeft" || collision->name == "PaddleRight") {
			velocity->x *= -1;
		} else { // Collided with left or right walls
			SDL_Quit();
		}
		collision = nullptr;
		return;
	}
	position->x += velocity->x;
	position->y += velocity->y;
}