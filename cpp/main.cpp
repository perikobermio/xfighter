    #include <iostream>
    #include <vector>
    #include <math.h>
    #include "constants"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "background.h"
    #include "player.h"
    #include "badBoss.h"

    render _ren;
    player _player;
    SDL_Renderer *ren;

    int main() {
        bool UP=false, DOWN=false, RIGHT=false, LEFT=false, FIRE=false;
        bool aktibo = true;
        int frametime;
        SDL_Event e;

        ren = _ren.createScreen(SCREEN_W, SCREEN_H);
        player::p1 cP1 = _player.getP1(); //hamen dakotez playerran dato danak
        background _background;
        badBoss _badBoss;

        //imagenak karga
        std::vector<background::back> vBack = _background.getBackgrounds(ren);
        _badBoss.loadBosses(ren);
        std::string nave = "../img/ships/p1/sprite.png";
        SDL_Texture* tNave = _ren.loadImages(nave, ren);

        while(aktibo) {
            frametime = SDL_GetTicks();
            while (SDL_PollEvent(&e)){
                if(e.type == SDL_KEYDOWN) { //teklarik sakatu badan beituten dau
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:   aktibo  = false;    break;
                        case SDLK_d:        RIGHT   = true;     break;
                        case SDLK_a:        LEFT    = true;     break;
                        case SDLK_w:        UP      = true;     break;
                        case SDLK_s:        DOWN    = true;     break;
                        case SDLK_RCTRL:    FIRE    = true;     break;
                    }
                } if(e.type == SDL_KEYUP) {
                    switch(e.key.keysym.sym) {
                        case SDLK_d:        RIGHT   = false;     break;
                        case SDLK_a:        LEFT    = false;     break;
                        case SDLK_w:        UP      = false;     break;
                        case SDLK_s:        DOWN    = false;     break;
                        case SDLK_RCTRL:    FIRE    = false;     break;
                    }
                }

            }

            //hau da framerate bardine imintzeko ordenadore danatan
            frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));


			_player.moveP1(LEFT, RIGHT, UP, DOWN, cP1);
			bool canFire = _player.cadenceControl(cP1, FIRE);
			
            if(FIRE && canFire) {
                _player.createFire(cP1);
            }            

            //renderize dana
            SDL_RenderClear(ren);
            _background.drawBackground(ren);
            _badBoss.drawBoss(ren);
            _player.drawFires(ren);
            _ren.renderTexture(tNave, ren, cP1.aSpr, SDL_Rect {cP1.x, cP1.y, cP1.w, cP1.h});
            SDL_RenderPresent(ren);

        }

        _ren.destroyEverything(vBack[0].img, tNave, ren);
        return 0;
    }
