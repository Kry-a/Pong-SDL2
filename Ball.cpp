//
// Created by krasno on 2020-01-26.
//

#include <effolkronium/random.hpp>
#include "Ball.h"

using Random = effolkronium::random_static;

void Ball::Bounce() {
    xVelocity = -xVelocity;
    yVelocity = Random::get(-8, 8);
}

void Ball::Update() {
    xPos += xVelocity;
    yPos += yVelocity;
}

Ball::Ball(float x, float y) {
    xVelocity = Random::get(4, 8);
    yVelocity = Random::get(-8, 8);
    radius = 10;
    xPos = x;
    yPos = y;
}
