#pragma once

#include "Entity.h"

class Wall : public Entity {
public:
	Wall(float x, float y, float width, float height, const std::string &name);
};