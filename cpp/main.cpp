    #include <iostream>
    #include <vector>
    #include <time.h>
    #include <math.h>
    #include <fstream>
    #include "/usr/include/jsoncpp/json/json.h"
    #include "constants"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "player.h"
    #include "bad.h"
    #include "collision.h"
    
    using namespace std;

    int main() {		
        bool UP=false, DOWN=false, RIGHT=false, LEFT=false, FIRE=false;
        bool running = true;
        int frametime;
        
        render _ren;
        player _player;
        bad _bad;
        collision _collision;
        
        
		_bad.loadConfig();
        SDL_Event e;
        
        _ren.createScreen(SCREEN_W, SCREEN_H);

        while(running) {
            frametime = SDL_GetTicks();
            while(SDL_PollEvent(&e)){
				if(e.type == SDL_QUIT) running  = false;
                if(e.type == SDL_KEYDOWN) {
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:   running = false;    					break;
                        case SDLK_1:   		_player.changeWeapon(_player.p1, 1);   	break;
                        case SDLK_2:   		_player.changeWeapon(_player.p1, 2);   	break;
                        case 1073741918:    RIGHT   = true;     					break;
                        case 1073741916:    LEFT    = true;     					break;
                        case 1073741920:    UP      = true;     					break;
                        case 1073741917:    DOWN    = true;     					break;
                        case SDLK_LCTRL:    FIRE    = true;     					break;
                    }
                } if(e.type == SDL_KEYUP) {
                    switch(e.key.keysym.sym) {
                        case 1073741918:    RIGHT   = false;     break;
                        case 1073741916:    LEFT    = false;     break;
                        case 1073741920:    UP      = false;     break;
                        case 1073741917:    DOWN    = false;     break;
                        case SDLK_LCTRL:    FIRE    = false;     break;
                    }
                }

            }
            //PLAYER
            _player.fire(_player, FIRE);
            _player.move(_player, RIGHT, LEFT, UP, DOWN);
            _collision.detect(_player,_bad);

            frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime)); 

            SDL_RenderClear(_ren.ren);
            _bad.draw(_ren.ren, _bad);
			_player.draw(_ren.ren, _player);
            SDL_RenderPresent(_ren.ren);
			SDL_SetRenderDrawColor(_ren.ren, 0, 0, 0, 255 );
        }
        _ren.destroyEverything(_ren);

        return 0;
    }
