#pragma once

#include "Entity.h"
#include <memory>

class Ball : public Entity {
public:
	Ball(float x, float y, float width, float height, float velX, float velY);
	void Update() override;
	std::unique_ptr<Vector2> velocity; // Direction and Speed
};