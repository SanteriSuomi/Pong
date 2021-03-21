#include "SDL.h"
#include "Entity.h"
#include <memory>

Entity::Entity(float x, float y, float width, float height) {
	this->position = std::make_unique<Vector2>(Vector2 {
		x,
		y
		});
	this->size = std::make_unique<Vector2>(Vector2 {
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

void Entity::Update() {
	// Overrideable
}