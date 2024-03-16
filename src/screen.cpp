#include "SDL2/SDL.h"
#include <string>

class Screen
{
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;

    public:
    Screen(const char *title, int width, int height)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            printf("error initializing SDL: %s\n", SDL_GetError());
        }
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    void clear()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
    }

    void render()
    {
        SDL_RenderPresent(renderer);
    }

    void drawPoint (int x, int y)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, x, y);
    }

    void drawLine (int x1, int y1, int x2, int y2)
    {   
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

        // "https://en.wikipedia.org/wiki/Bresenham's_line_algorithm"

        int dx = abs(x2 - x1);
        int sx = x1 < x2 ? 1 : -1;
        int dy = -abs(y2 - y1);
        int sy = y1 < y2 ? 1 : -1;
        int error = dx + dy;

        while (true) {
            SDL_RenderDrawPoint(renderer, x1, y1);
            if (x1 == x2 && y1 == y2) break;
            int e2 = 2 * error;
            if (e2 >= dy) {
                if (x1 == x2) break;
                error += dy;
                x1 += sx;
            }
            if (e2 <= dx) {
                if (y1 == y2) break;
                error = error + dx;
                y1 += sy;
            }
        }
    }

    void input()
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                exit(EXIT_SUCCESS);
            }
        }
    }
};
