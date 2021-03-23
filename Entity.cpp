#include "SDL.h"
#include "Entity.h"
#include <memory>

Entity::Entity(float x, float y, float width, float height) {
	this->position = std::make_unique<Vector2<float>>(Vector2<float> {
		x,
		y
		});
	this->size = std::make_unique<Vector2<float>>(Vector2<float> {
		width,
		height
		});
}

void Entity::Draw(SDL_Renderer *renderer) const {
	SDL_Rect rect {
		static_cast<int>(position->x),
		static_cast<int>(position->y),
		static_cast<int>(size->x),
		static_cast<int>(size->y)
	};
	SDL_RenderFillRect(renderer, &rect);
}

void Entity::Update(float deltaTime, const Entity *collision) {
	// Overrideable
}

void Entity::Move(float x, float y) const {
	position->x += x;
	position->y += y;
}

bool Entity::Collides(const Entity *entity) const {
	if (!entity) return false;
	if (position->x + size->x / 2 < entity->position->x - entity->size->x / 2) return false;
	if (position->x - size->x / 2 > entity->position->x + entity->size->x / 2) return false;
	if (position->y + size->y / 2 < entity->position->y - entity->size->y / 2) return false;
	if (position->y - size->y / 2 > entity->position->y + entity->size->y / 2) return false;
	return true;
}