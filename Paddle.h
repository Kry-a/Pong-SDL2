//
// Created by krasno on 2020-01-26.
//

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H


#include <SDL_rect.h>
#include <SDL_render.h>

class Paddle {
public:
    SDL_Color colour{.r = 255, .g = 255, .b = 255, .a = 255};
    SDL_Rect rect{};
    double xPos;
    double yPos;

public:
    Paddle(float x, float y);
    void Render(SDL_Renderer *pRenderer);
    SDL_Rect *GetCurrentRect();
};


#endif //PONG_PADDLE_H
