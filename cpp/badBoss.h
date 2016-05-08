#ifndef badBoss_h
#define badBoss_h

class badBoss {
	private:
		render _ren;
		SDL_Texture* tBad;
		SDL_Rect spr = {610,640,270,300};
		int x = SCREEN_W/2-200, y = -700;
		
		int move = 0, kont = 0, waitTime = 0;
		int inmove = 1;
    public:
		void loadBosses(SDL_Renderer *ren) {
			std::string bad = "../img/ships/bad/badSprite.png";
            tBad = _ren.loadImages(bad, ren);
		}
    
		void drawBoss(SDL_Renderer *ren) {
			if(inmove) bossMovements(move);
			else {
				++kont;
				if(kont>=waitTime) {
					inmove = 1;
					kont = 0;
				}
			}
			
			SDL_Rect dst = {x,y,400,550};
			SDL_RenderCopy(ren, tBad, &spr, &dst);
		}
		
    private:
       
		void bossMovements(int muf) {
			switch(muf) {
				case 0:
					if(y<-150) y += 1;
					else {
						move = 1;
						inmove = 0;
						waitTime = 60;
					}
				break;
				
				case 1:
					if(x>=0) x -= 2;
					else {
						move = 2;
						inmove = 0;
						waitTime = 100;
					}
				break;
				
				case 2:
					if(x<=SCREEN_W-400) x += 2;
					else {
						move = 1;
						inmove = 0;
						waitTime = 100;
					}
				break;
			}
			
		}

};

#endif
