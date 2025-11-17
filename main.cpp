#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char* argv[]) {

    // Sprawdzanie errorów
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);
    bool running = true;
    SDL_Rect player{10,10,250,250};


    SDL_CreateWindowAndRenderer(1280,720, 0, &window, &renderer);

    auto red_texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1280, 720 );

    auto blue_texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1280, 720 );


    SDL_SetRenderTarget(renderer,red_texture);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer,blue_texture);
    SDL_SetRenderDrawColor(renderer, 0,0,255,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget(renderer,nullptr);

    SDL_RenderCopy(renderer,red_texture,nullptr,nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);

    SDL_RenderCopy(renderer,blue_texture,nullptr,nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    // while (running) {
    //     while (SDL_PollEvent(&e)) {
    //         if (e.type == SDL_QUIT) {
    //             running = false;
    //         }
    //         if (e.type == SDL_KEYDOWN) {
    //             switch (e.key.keysym.sym) {
    //                 case SDLK_RIGHT:
    //                     player.x += 50;
    //                     break;
    //                 case SDLK_LEFT:
    //                     player.x -= 50;
    //                     break;
    //                 case SDLK_UP:
    //                     player.y -= 50;
    //                     break;
    //                 case SDLK_DOWN:
    //                     player.y += 50;
    //                     break;
    //             }
    //         }
    //         else if (e.type == SDL_MOUSEMOTION) {
    //             SDL_GetMouseState(&player.x,&player.y);
    //         }
    //     }
        // SDL_SetRenderDrawColor(renderer,  0,0,0,255);
        // SDL_RenderClear(renderer);
        //
        // SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        // SDL_RenderFillRect(renderer, &player);

    //     SDL_RenderPresent(renderer);
    //     SDL_Delay(10);
    // }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();



    return 0;
}