#include <iostream>
#include <SDL2/SDL.h>
#include "Paddle.h"
#include "Ball.h"

// Declares the width and height of the render area of the window
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 256

// Declares the speed which the paddle should move
#define PADDLE_SPEED 150

// If the game is supposed to be played by two people
bool twoPlayers = true;

// Delta time stuff
Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;
double deltaTime = 0;

bool playing = true;
Paddle leftPaddle(11, SCREEN_HEIGHT / 2 - 33);
Paddle rightPaddle(SCREEN_WIDTH - 14, SCREEN_HEIGHT / 2 - 33);
Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

void ProcessEvents(SDL_Event& pEvent, SDL_Window& pWindow);
void Controls();
void Render(SDL_Renderer *pRenderer, SDL_Window *pWindow);

int main() {
    // Declare stuff for SDL2
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    // Init the video thingy
    SDL_Init(SDL_INIT_VIDEO);
    // Create Window and Renderer
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // A loop that executes when we are still playing the game
    while (playing) {
        // Calculating delta time
        // Delta time is simply the time it takes for a frame to render
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = ((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;

        // Process all the events
        ProcessEvents(event, *window);
        Controls();



        // Renders everything to the screen
        Render(renderer, window);
    }

    // Closes the game when we are finished playing
    SDL_Quit();
    return 0;
}

/**
 * Process all events in the game
 * @param pEvent The main @see SDL_Event
 * @param pWindow Window which events are being captured from
 */
void ProcessEvents(SDL_Event& pEvent, SDL_Window& pWindow) {
    // Iterates through every event in the queue until there are none left to process
    while (SDL_PollEvent(&pEvent) != 0) {
        SDL_PumpEvents();

        // If the close button on the window is pressed we change the playing status to false
        if (pEvent.type == SDL_QUIT)
            playing = false;
    }
}

/**
 * Process controls
 */
void Controls() {
    // Get the current state of the keyboard
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // If the ESC key is pressed we change the playing status to false
    if (state[SDL_SCANCODE_ESCAPE]) {
        playing = false;
    }

    // Check to see if the game is running in two players mode
    if (twoPlayers) {
        // Player 1
        if (state[SDL_SCANCODE_W]) {
            double move = PADDLE_SPEED * deltaTime;
            if (leftPaddle.yPos - move <= 0)
                leftPaddle.yPos = 0;
            else
                leftPaddle.yPos -= move;
        }

        if (state[SDL_SCANCODE_S]) {
            double move = PADDLE_SPEED * deltaTime;
            if (leftPaddle.yPos + leftPaddle.rect.h + move >= SCREEN_HEIGHT)
                leftPaddle.yPos = SCREEN_HEIGHT - leftPaddle.rect.h;
            else
                leftPaddle.yPos += move;
        }

        // Player 2
        if (state[SDL_SCANCODE_UP]) {
            double move = PADDLE_SPEED * deltaTime;
            if (rightPaddle.yPos - move <= 0)
                rightPaddle.yPos = 0;
            else
                rightPaddle.yPos -= move;
        }

        if (state[SDL_SCANCODE_DOWN]) {
            double move = PADDLE_SPEED * deltaTime;
            if (rightPaddle.yPos + rightPaddle.rect.h + move >= SCREEN_HEIGHT)
                rightPaddle.yPos = SCREEN_HEIGHT - rightPaddle.rect.h;
            else
                rightPaddle.yPos += move;
        }
    } else {
        if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
            double move = PADDLE_SPEED * deltaTime;
            if (leftPaddle.yPos - move <= 0)
                leftPaddle.yPos = 0;
            else
                leftPaddle.yPos -= move;
        }

        if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) {
            double move = PADDLE_SPEED * deltaTime;
            if (leftPaddle.yPos + leftPaddle.rect.h + move >= SCREEN_HEIGHT)
                leftPaddle.yPos = SCREEN_HEIGHT - leftPaddle.rect.h;
            else
                leftPaddle.yPos += move;
        }
    }
}

/**
 * Renders everything
 * @param pRenderer Target renderer
 * @param pWindow Active window
 */
void Render(SDL_Renderer *pRenderer, SDL_Window *pWindow) {
    // Clearing the screen with a dark-ish colour
    SDL_SetRenderDrawColor(pRenderer, 53, 53, 53, 255);
    SDL_RenderClear(pRenderer);

    // Drawing the middle line
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(pRenderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    SDL_RenderDrawLine(pRenderer, SCREEN_WIDTH / 2 + 1, 0, SCREEN_WIDTH / 2 + 1, SCREEN_HEIGHT);

    // Render both paddles
    leftPaddle.Render(pRenderer);
    rightPaddle.Render(pRenderer);

    // TODO: Render the ball

    // Finally render it all out
    SDL_RenderPresent(pRenderer);
}
