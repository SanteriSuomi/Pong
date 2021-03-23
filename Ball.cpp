#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, float velX, float velY) : Entity::Entity(x, y, width, height) {
	velocity = std::make_unique<Vector2<float>>(Vector2<float> {
		velX,
		velY
		});
}

void Ball::Update(float deltaTime, const Entity *collision) {
	position->x += velocity->x;
	position->y += velocity->y;
}