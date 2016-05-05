
    #include <iostream>
    #include <vector>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "player.h"

    const int SCREEN_W = 1024;
    const int SCREEN_H = 768;

    int main() {
        bool UP=false, DOWN=false, RIGHT=false, LEFT=false, FIRE=false;
        bool aktibo = true;
        int frametime;
        SDL_Event e;

        render _ren;
        player _player;

        SDL_Renderer *ren = _ren.createScreen(SCREEN_W, SCREEN_H);

        player::p1 cP1 = _player.getP1(); //hamen dakotez playerran dato danak
        //imagenak karga
        std::string space = "./../img/space.png";
        SDL_Texture* tSpace = _ren.loadImages(space, ren);
        std::string nave = "./../img/ships/p1/sprite.png";
        SDL_Texture* tNave = _ren.loadImages(nave, ren);

        while(aktibo) {
            frametime = SDL_GetTicks();
            while (SDL_PollEvent(&e)){
                if(e.type == SDL_KEYDOWN) { //teklarik sakatu badan beituten dau
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:   aktibo  = false;    break;
                        case SDLK_RIGHT:    RIGHT   = true;     break;
                        case SDLK_LEFT:     LEFT    = true;     break;
                        case SDLK_UP:       UP      = true;     break;
                        case SDLK_DOWN:     DOWN    = true;     break;
                        case SDLK_SPACE:    FIRE   = true;     break;
                    }
                } if(e.type == SDL_KEYUP) {
                    switch(e.key.keysym.sym) {
                        case SDLK_RIGHT:    RIGHT   = false;     break;
                        case SDLK_LEFT:     LEFT    = false;     break;
                        case SDLK_UP:       UP      = false;     break;
                        case SDLK_DOWN:     DOWN    = false;     break;
                        case SDLK_SPACE:    FIRE   = false;     break;
                    }
                }

            }

            //hau da framerate bardine imintzeko ordenadore danatan
            frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));

            if(LEFT) {
                cP1.x -= cP1.v;
                cP1.aSpr = cP1.sprL5;
            }
            if(RIGHT) {
                cP1.x += cP1.v;
                cP1.aSpr = cP1.sprR5;
            }
            if(UP) {
                cP1.y -= cP1.v;
            }
            if(DOWN) {
                cP1.y += cP1.v;
            }
            if(FIRE) {
                _player.createFire(0, cP1.x, cP1.y, cP1.w, cP1.h);
            }

            if(!LEFT && !RIGHT && !UP && !DOWN) {
                cP1.aSpr = cP1.spr0;
            }


            SDL_RenderClear(ren);
            _ren.renderTexture(tSpace, ren, SDL_Rect {0,0,SCREEN_W,SCREEN_H}, 0, 0, SCREEN_W, SCREEN_H); //imagena imintzen dau diñotzagun pixelatan, imagenan neurri originalakaz
            _player.drawFires(ren);
            _ren.renderTexture(tNave, ren, cP1.aSpr, cP1.x, cP1.y, cP1.w, cP1.h); //imagena imintzen dau diñotzagun pixelatan, imagenan neurri originalakaz

            SDL_RenderPresent(ren);
        }

        _ren.destroyEverything(tSpace, tNave, ren);
        return 0;
    }
