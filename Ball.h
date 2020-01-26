//
// Created by krasno on 2020-01-26.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SDL_rect.h>

class Ball {
public:
    float xVelocity;
    float yVelocity;
    float radius;
    float xPos;
    float yPos;

public:
    void Bounce();
    void Update();
};


#endif //PONG_BALL_H
