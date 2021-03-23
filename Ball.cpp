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
		velocity->x *= -1;
		collision = nullptr;
		return;
	}
	position->x += velocity->x;
	position->y += velocity->y;
}