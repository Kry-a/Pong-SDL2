//
// Created by krasno on 2020-01-26.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SDL_rect.h>
#include <SDL_render.h>

class Ball {
public:
    float xVelocity;
    float yVelocity;
    int radius;
    float xPos;
    float yPos;

public:
    void Bounce();
    void Update();
    Ball(int x, int y);
    void Render(SDL_Renderer *pRenderer);
};


#endif //PONG_BALL_H
