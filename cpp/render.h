#ifndef render_h
#define render_h

class render {
    private:
        SDL_Window *screen;

    public:
        SDL_Renderer *ren;

        SDL_Renderer* createScreen(const int SCREEN_W, const int SCREEN_H) {
            screen = SDL_CreateWindow("xfighter", 0, 0, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
            ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        }

        void destroyEverything(render _ren) {
            SDL_DestroyRenderer(_ren.ren);
            SDL_DestroyWindow(_ren.screen);

            IMG_Quit();
            SDL_Quit();
        }

};

#endif
