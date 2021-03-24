#pragma once

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

const int WALL_THICKNESS = 25;
const int PADDLE_HEIGHT = 100;

// Starting ball velocity
const float BALL_VEL_X = -12.5F;
const float BALL_VEL_Y = -1.5F;

const float FRAME_TIME = 16.66F;
const float MAX_DELTA_TIME = 0.05F;

const float PADDLE_SPEED = 400.0F;

const float COLLISION_WAIT_PERIOD = 49.98F; // Mandatory waiting period until object can collide again