//
// Created by krasno on 2020-01-26.
//

#ifndef PONG_UTILS_H
#define PONG_UTILS_H


#include <SDL_pixels.h>
#include <SDL_render.h>

class Utils {
public:
    static int SetDrawColour(SDL_Renderer *renderer, SDL_Color c);
    static void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
};


#endif //PONG_UTILS_H
