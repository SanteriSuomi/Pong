#pragma once

#include "SDL.h"
#include "Vector2.h"
#include <memory>

class Entity {
public:
	Entity(float x, float y, float width, float height);
	void Draw(SDL_Renderer *renderer) const;
	virtual void Update(float deltaTime, const Entity *collision);
	void Move(float x, float y) const;
	bool Collides(const Entity *entity) const;
	std::unique_ptr<Vector2<float>> position; // X, Y
	std::unique_ptr<Vector2<float>> size; // Width, Height
};