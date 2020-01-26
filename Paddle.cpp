//
// Created by krasno on 2020-01-26.
//

#include "Paddle.h"
#include "Utils.h"

void Paddle::Render(SDL_Renderer *pRenderer) {
    Utils::SetDrawColour(pRenderer, colour);
    SDL_RenderFillRect(pRenderer, GetCurrentRect());
}

Paddle::Paddle(float x, float y) {
    xPos = x;
    yPos = y;
    rect.x = (int)x;
    rect.y = (int)y;
    rect.w = 4;
    rect.h = 32;
}

SDL_Rect *Paddle::GetCurrentRect() {
    rect.x = (int)xPos;
    rect.y = (int)yPos;
    return &rect;
}
