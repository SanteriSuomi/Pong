#pragma once

#include "SDL.h"
#include "Vector2.h"
#include <string>
#include <memory>

class Entity {
public:
  Entity(float x, float y, float width, float height, const std::string &name);
	void Draw(SDL_Renderer *renderer) const;
	virtual void Update(float deltaTime);
	void Move(float x, float y) const;
	bool Collides(const Entity *entity) const;
	bool Collides(const Vector2<float> pos, const Vector2<float> size) const;
	std::unique_ptr<Vector2<float>> position; // X, Y
	std::unique_ptr<Vector2<float>> size; // Width, Height
	std::string name;

	Entity *collision = nullptr; // Will contain the entity this entity collided with when collision happens
	Uint32 collisionTicks = 0;
};