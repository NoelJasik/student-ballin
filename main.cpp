#include <iostream>
#include <SDL.h>


int main(int argc, char* argv[]) {

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640,480, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,4,4);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderDrawPoint(renderer, 640/8,480/8);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);


    return 0;
}