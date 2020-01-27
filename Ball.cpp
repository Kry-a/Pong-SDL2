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

void Ball::CheckCollision(Paddle lPaddle, Paddle rPaddle, int w, int h) {
    if (xPos >= (float)w - (float)radius / 2 || xPos <= (float)radius / 2)
        xVelocity = -xVelocity;
    if (yPos >= (float)h - (float)radius / 2 || yPos <= (float)radius / 2)
        yVelocity = -yVelocity;
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
