#pragma once
#include "Headers.h"

//Screen const settings
constexpr unsigned short SCREEN_WIDTH_QHD = 2560;
constexpr unsigned short SCREEN_HEIGHT_QHD = 1440;

constexpr unsigned short SCREEN_WIDTH_FHD = 1920;
constexpr unsigned short SCREEN_HEIGHT_FHD = 1080;

constexpr unsigned short SCREEN_WIDTH_HD_PLUS = 1600;
constexpr unsigned short SCREEN_HEIGHT_HD_PLUS = 900;

constexpr unsigned short SCREEN_WIDTH_HD = 1280;
constexpr unsigned short SCREEN_HEIGHT_HD = 720;

constexpr std::chrono::microseconds FRAME_DURATION_120(8333); //120FPS
constexpr std::chrono::microseconds FRAME_DURATION_60(16667); //60FPS
constexpr std::chrono::microseconds FRAME_DURATION_30(33333); //30FPS

//Player const settings
//constexpr float GRAVITY = 0.25f;
//constexpr float PLAYER_ACCELERATION = 0.25f;
//constexpr float PLAYER_JUMP_SPEED = -4;
//constexpr float PLAYER_WALK_SPEED = 2;
//constexpr float MAX_VERTICAL_SPEED = 8;
//constexpr unsigned short PLAYER_WALK_ANIMATION_SPEED = 4;
