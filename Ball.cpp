//
// Created by krasno on 2020-01-26.
//

#include "Ball.h"

void Ball::Bounce() {
    xVelocity = -xVelocity;
    // TODO: add new thingy for randomness for yVelocity
}

void Ball::Update() {
    xPos += xVelocity;
    yPos += yVelocity;
}
