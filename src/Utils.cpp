//
// Created by krasno on 2020-01-26.
//

#include "Utils.h"

/**
 * Sets the Render draw colour with a @see SDL_Color
 * @param renderer
 * @param c The desired colour for rendering (alpha is omitted)
 * @return Returns 0 if the code has been successfully executed
 */
int Utils::SetDrawColour(SDL_Renderer *renderer, SDL_Color c) {
    return SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, 255);
}

/**
 * Draws a filled circle on screen
 * From [StackOverflow](https://stackoverflow.com/a/48291620)
 * @param renderer Target renderer
 * @param centreX X coordinate for the centre of the circle
 * @param centreY Y coordinate for the centre of the circle
 * @param radius Radius to be drawn from the centre of the origin point
 */
void Utils::DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    while (x >= y) {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Utils::DrawFilledCircle(SDL_Renderer *pRenderer, int centreX, int centreY, int radius) {
    for (int i = radius; i > 0; i--) {
        DrawCircle(pRenderer, centreX, centreY, i);
    }
}
