#include "SDL.h"
#include "Entity.h"
#include <memory>

Entity::Entity(float x, float y, float width, float height) {
	this->position = std::make_unique<Vector2>(Vector2 {
		x,
		y
		});
	this->size = std::make_unique<Vector2>(Vector2{
		width,
		height
		});
}

void Entity::Draw(SDL_Renderer *renderer) const {
	SDL_Rect rect {
		static_cast<int>(position.get()->x),
		static_cast<int>(position.get()->y),
		static_cast<int>(size.get()->x),
		static_cast<int>(size.get()->y)
	};
	SDL_RenderFillRect(renderer, &rect);
}