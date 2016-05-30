    #include <iostream>
    #include <vector>
    #include <math.h>
    #include "constants"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "player.h"

    int main() {
		
        bool UP=false, DOWN=false, RIGHT=false, LEFT=false, FIRE=false;
        bool running = true;
        int frametime;
        
        render _ren;
        player _player;
        SDL_Event e;
        
        _ren.createScreen(SCREEN_W, SCREEN_H);

        while(running) {
            frametime = SDL_GetTicks();
            while(SDL_PollEvent(&e)){
				if(e.type == SDL_QUIT) running  = false;
                if(e.type == SDL_KEYDOWN) {
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:   running = false;    break;
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
            //MOVEMENTS
            _player.move(_player.p1, RIGHT, LEFT, UP, DOWN);

            frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime)); 

            SDL_RenderClear(_ren.ren);
			_player.drawPlayer(_ren.ren, _player.p1);
            SDL_RenderPresent(_ren.ren);

        }
        _ren.destroyEverything(_ren);

        return 0;
    }
