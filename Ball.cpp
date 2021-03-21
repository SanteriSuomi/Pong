#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, float velX, float velY) : Entity::Entity(x, y, width, height) {
	velocity = std::make_unique<Vector2>(Vector2 {
		velX,
		velY
		});
}

void Ball::Update() {
	position->x += velocity->x;
	position->y += velocity->y;
}