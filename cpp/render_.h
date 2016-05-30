#ifndef render_h
#define render_h

class render {
    private:
        SDL_Window *screen;

    public:
        SDL_Renderer *ren;

        SDL_Renderer* createScreen(const int SCREEN_W, const int SCREEN_H) {
            render::screen = SDL_CreateWindow("xfighter", 0, 0, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
            SDL_Renderer *render = SDL_CreateRenderer(render::screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            render::ren = render;
            return render;
        }

        SDL_Texture* loadImages(std::string _img, SDL_Renderer *ren) {
            SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, img);
            SDL_FreeSurface(img);
            return texture;
        }

        void destroyEverything(SDL_Texture* tSpace, SDL_Texture* tNave, SDL_Renderer *ren) {
            SDL_DestroyTexture(tSpace);
            SDL_DestroyTexture(tNave);
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(render::screen);

            IMG_Quit();
            SDL_Quit();
        }

        void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect spr, SDL_Rect dst) {
            SDL_RenderCopy(ren, tex, &spr, &dst);
        }
};

#endif
