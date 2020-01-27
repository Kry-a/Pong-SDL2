//
// Created by krasno on 2020-01-26.
//

#include <effolkronium/random.hpp>
#include "Ball.h"
#include <SDL2/SDL2_gfxPrimitives.h>

using Random = effolkronium::random_static;

void Ball::Bounce() {
    xVelocity = -xVelocity;
    yVelocity = Random::get(-8, 8);
}

void Ball::Update() {
    xPos += xVelocity;
    yPos += yVelocity;
}

void Ball::CheckCollision(Paddle &lPaddle, Paddle &rPaddle, int w, int h, int &pScoreA, int &pScoreB) {
    // Test if the ball is colliding with the border of the screen
    if (xPos >= (float)w - (float)radius) {
        xVelocity = -xVelocity;
        pScoreB++;
    } else if (xPos <= (float)radius) {
        xVelocity = -xVelocity;
        pScoreA++;
    }

    if (yPos >= (float)h - (float)radius || yPos <= (float)radius)
        yVelocity = -yVelocity;

    // Left paddle collision testing
    if (xPos - (float)radius < lPaddle.xPos + lPaddle.rect.w && xPos + (float)radius > lPaddle.xPos &&
        yPos - (float)radius < lPaddle.yPos + lPaddle.rect.h && yPos + (float)radius > lPaddle.yPos)
        Bounce();

    // Right paddle collision testing
    if (xPos - (float)radius < rPaddle.xPos + rPaddle.rect.w && xPos + (float)radius > rPaddle.xPos &&
        yPos - (float)radius < rPaddle.yPos + rPaddle.rect.h && yPos + (float)radius > rPaddle.yPos)
        Bounce();
}

Ball::Ball(int x, int y) {
    xVelocity = Random::get(4, 8);
    yVelocity = Random::get(-8, 8);
    radius = 10;
    xPos = (float)x;
    yPos = (float)y;
}

void Ball::Render(SDL_Renderer *pRenderer) {
    filledCircleRGBA(pRenderer, xPos, yPos, radius, colour.r, colour.g, colour.b, colour.a);
}
