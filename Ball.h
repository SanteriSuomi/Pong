#pragma once

#include "Entity.h"
#include <memory>

class Ball : public Entity {
public:
	Ball(float x, float y, float width, float height, float velX, float velY);
	void Update(float deltaTime, const Collision* collision) override;
	std::unique_ptr<Vector2<float>> velocity; // Direction and Speed
};