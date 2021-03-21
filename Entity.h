#pragma once

#include "SDL.h"
#include "Vector2.h"
#include <memory>

class Entity {
public:
	Entity(float x, float y, float width, float height);
	void Draw(SDL_Renderer *renderer) const;
private:
	std::unique_ptr<Vector2> position; // X, Y
	std::unique_ptr<Vector2> size; // Width, Height
};