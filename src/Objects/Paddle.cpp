//
// Created by krasno on 2020-01-26.
//

#include "Paddle.h"
#include "../Utils.h"

/**
 * Renders the paddle to the target @see SDL_Renderer
 * @param pRenderer The target renderer
 */
void Paddle::Render(SDL_Renderer *pRenderer) {
    Utils::SetDrawColour(pRenderer, colour);
    SDL_RenderFillRect(pRenderer, GetCurrentRect());
}

/**
 * Constructs a paddle
 * @param x The X position of the left top of the paddle
 * @param y The Y position of the left top of the paddle
 */
Paddle::Paddle(float x, float y) {
    xPos = x;
    yPos = y;
    rect.x = (int)x;
    rect.y = (int)y;
    rect.w = 4;
    rect.h = 32;
}

/**
 * Updates X and Y values and returns the current @see SDL_Rect
 * @return
 */
SDL_Rect *Paddle::GetCurrentRect() {
    rect.x = (int)xPos;
    rect.y = (int)yPos;
    return &rect;
}
