
    #include <iostream>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "player.h"

    const int SCREEN_W = 1024;
    const int SCREEN_H = 768;


    int main() {
        bool UP=false, DOWN=false, RIGHT=false, LEFT=false;
        bool aktibo = true;
        SDL_Event e;

        render _ren;
        player _player;

        SDL_Renderer *ren = _ren.createScreen(SCREEN_W, SCREEN_H);

        player::p1 cP1 = _player.getP1(); //hamen dakotez playerran dato danak
        //imagenak karga
        std::string space = "./../img/space.png";
        SDL_Texture* tSpace = _ren.loadImages(space, ren);
        std::string nave = "./../img/ships/p1/p0.png";
        SDL_Texture* tNave = _ren.loadImages(nave, ren);

        while(aktibo) {
            while (SDL_PollEvent(&e)){
                if(e.type == SDL_KEYDOWN) { //teklarik sakatu badan beituten dau
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:   aktibo  = false;    break;
                        case SDLK_RIGHT:    RIGHT   = true;     break;
                        case SDLK_LEFT:     LEFT    = true;     break;
                        case SDLK_UP:       UP      = true;     break;
                        case SDLK_DOWN:     DOWN    = true;     break;
                    }
                } if(e.type == SDL_KEYUP) {
                    switch(e.key.keysym.sym) {
                        case SDLK_RIGHT:    RIGHT   = false;     break;
                        case SDLK_LEFT:     LEFT    = false;     break;
                        case SDLK_UP:       UP      = false;     break;
                        case SDLK_DOWN:     DOWN    = false;     break;
                    }
                }

            }

            if(LEFT) {
                cP1.x -= cP1.v;
            }
            if(RIGHT) {
                cP1.x += cP1.v;
            }
            if(UP) {
                cP1.y -= cP1.v;
            }
            if(DOWN) {
                cP1.y += cP1.v;
            }

            SDL_RenderClear(ren);
            _ren.renderTexture(tSpace, ren, 0, 0, SCREEN_W, SCREEN_H); //imagena imintzen dau diñotzagun pixelatan, imagenan neurri originalakaz
            _ren.renderTexture(tNave, ren, cP1.x, cP1.y, 87, 80); //imagena imintzen dau diñotzagun pixelatan, imagenan neurri originalakaz
            SDL_RenderPresent(ren);
        }

        _ren.destroyEverything(tSpace, tNave, ren);
        return 0;
    }
