//
// Created by krasno on 2020-01-26.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SDL_rect.h>
#include <SDL_render.h>
#include "Paddle.h"

class Ball {
public:
    float xVelocity;
    float yVelocity;
    int radius;
    float xPos;
    float yPos;
    SDL_Color colour{.r = 255, .g = 255, .b = 255, .a = 255};

public:
    void Bounce();
    void Update();
    void CheckCollision(Paddle lPaddle, Paddle rPaddle, int w, int h);
    Ball(int x, int y);
    void Render(SDL_Renderer *pRenderer);
};


#endif //PONG_BALL_H
