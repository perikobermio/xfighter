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
            _player.move(_player.p1, RIGHT, LEFT, UP, DOWN, FIRE);

            frametime = SDL_GetTicks() - frametime;
<<<<<<< HEAD
            if(frametime < 10)SDL_Delay(Uint32(10-frametime)); 
=======
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));


			_player.moveP1(LEFT, RIGHT, UP, DOWN, cP1);
			bool canFire = _player.cadenceControl(cP1, FIRE);
			
            if(FIRE && canFire) {
                _player.createFire(cP1);
            }
            
            int katapum = _colision.detectColision(_badBoss, _player, cP1);       
            if(katapum) aktibo = false;
>>>>>>> 2b2aafe9696dd8768b6f58f01eca97c7737c3142

            SDL_RenderClear(_ren.ren);
			_player.drawPlayer(_ren.ren, _player.p1);
            SDL_RenderPresent(_ren.ren);

        }
        _ren.destroyEverything(_ren);

        return 0;
    }
