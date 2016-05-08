#ifndef badBoss_h
#define badBoss_h

class badBoss {
    public:
		void loadBosses(SDL_Renderer *ren) {
			std::string bad = "../img/ships/bad/badSprite.png";
            tBad = _ren.loadImages(bad, ren);
		}
    
		void drawBoss(SDL_Renderer *ren) {
			bossMovements();
			SDL_Rect dst = {x,y,400,550};
			SDL_RenderCopy(ren, tBad, &spr, &dst);
		}
		
    private:
		render _ren;
		SDL_Texture* tBad;
		SDL_Rect spr = {610,640,270,300};
		int x = SCREEN_W/2-200, y = -700, v = 1;
       
		void bossMovements() {
		   if(y<-150) y += v;
		}

};

#endif
