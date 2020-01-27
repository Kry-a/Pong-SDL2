//
// Created by krasno on 2020-01-26.
//

#include <effolkronium/random.hpp>
#include "Ball.h"
#include <SDL2/SDL2_gfxPrimitives.h>

using Random = effolkronium::random_static;

/**
 * Inverts the ball X velocity and returns a new random Y velocity
 */
void Ball::Bounce() {
    xVelocity = -xVelocity;
    yVelocity = Random::get(-6, 6);
}

/**
 * Adds the ball velocity to it's position
 * Needs to be executed every frame
 */
void Ball::Update() {
    xPos += xVelocity;
    yPos += yVelocity;
}

/**
 * Checks if the ball is colliding with edges of the screen or with a paddle
 * @param lPaddle Left paddle
 * @param rPaddle Right paddle
 * @param w Width of the current window
 * @param h Height of the current window
 * @param pScoreA The score of player A
 * @param pScoreB The score of player B
 * @return If the ball has hit the wall and scored a point
 */
bool Ball::CheckCollision(Paddle &lPaddle, Paddle &rPaddle, int w, int h, int &pScoreA, int &pScoreB) {
    // Test if the ball is colliding with the border of the screen
    if (xPos >= (float)w - (float)radius) {
        xVelocity = -xVelocity;
        pScoreA++;

        // Return the ball to the original place
        RestartBall();
        return true;
    } else if (xPos <= (float)radius) {
        xVelocity = -xVelocity;
        pScoreB++;

        // Return the ball to the original place
        RestartBall();
        return true;
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

    return false;
}

/**
 * Initializes the ball class
 * @param x Where the ball should be placed on the screen in the X axis
 * @param y Where the ball should be placed on the screen in the Y axis
 */
Ball::Ball(int x, int y) {
    xVelocity = Random::get(4, 6);
    yVelocity = Random::get(-6, 6);
    radius = 10;
    xPos = (float)x;
    yPos = (float)y;
    xOrigin = (float)x;
    yOrigin = (float)y;
}

/**
 * Renders the ball in the target @see SDL_Renderer
 * @param pRenderer The target renderer
 */
void Ball::Render(SDL_Renderer *pRenderer) {
    filledCircleRGBA(pRenderer, xPos, yPos, radius, colour.r, colour.g, colour.b, colour.a);
}

/**
 * Returns the ball to it's original place
 */
void Ball::RestartBall() {
    xVelocity = Random::get(4, 6);
    yVelocity = Random::get(4, 6);

    xPos = xOrigin;
    yPos = yOrigin;
}
