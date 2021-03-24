#include "Entity.h"

Entity::Entity(float x, float y, float width, float height, const std::string &name) : name(name) {
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

void Entity::Update(float deltaTime) {
	// Overrideable
}

void Entity::Move(float x, float y) const {
	position->x += x;
	position->y += y;
}

bool Entity::Collides(const Entity *entity) const {
	if (!entity) return false;
	if (position->x < entity->position->x + entity->size->x &&
		position->x + size->x > entity->position->x &&
		position->y < entity->position->y + entity->size->y &&
		position->y + size->y > entity->position->y) {
		return true;
	}
	return false;
}

bool Entity::Collides(const Vector2<float> pos, const Vector2<float> sz) const {
	if (position->x < pos.x + sz.x &&
		position->x + size->x > pos.x &&
		position->y < pos.y + pos.y &&
		position->y + size->y > pos.y) {
		return true;
	}
	return false;
}