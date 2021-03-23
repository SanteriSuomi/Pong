#pragma once

#include "Entity.h"
#include <string>
#include <memory>

class Ball : public Entity {
public:
	Ball(float x, float y, float width, float height, float velX, float velY, const std::string &name);
	void Update(float deltaTime) override;
	std::unique_ptr<Vector2<float>> velocity; // Direction and Speed
};