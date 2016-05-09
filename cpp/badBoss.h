#ifndef badBoss_h
#define badBoss_h

class badBoss {
	private:
		render _ren;
		SDL_Texture* tBad;
        SDL_Texture* tShots;
		SDL_Rect spr = {610,640,270,300};
		int x = SCREEN_W/2-200, y = -700;
		
		int move = 0, kont = 0, waitTime = 0;
		int inmove = 1;


        /////////////
        struct fire {int type, x, y, x2, h2, v;};
        struct fireSpr {
            SDL_Rect f1 = {0,47,20,20};
        } fSpr;
        std::vector<fire> vFire;


    public:
		void loadBosses(SDL_Renderer *ren) {
			std::string bad = "../img/ships/bad/badSprite.png";
            tBad = _ren.loadImages(bad, ren);

            std::string shots = "../img/shot/shots.png";
            tShots = _ren.loadImages(shots, ren);
            //vFire.push_back(fire({0,0,0,50,50,10}));
		}
    
		void drawBoss(SDL_Renderer *ren) {
            drawFires(ren);
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

        void drawFires(SDL_Renderer *ren) {
            SDL_Rect dst = {0,0,fSpr.f1.w,fSpr.f1.h};
            SDL_RenderCopy(ren, tShots, &fSpr.f1, &dst);
        }
       
		void bossMovements(int muf) {
			switch(muf) {
				case 0:
					if(y<-150) y += 1;
					else {
						move = 1;
						inmove = 0;
                        waitTime = 120;
					}
				break;
				
				case 1:
					if(x>=0) x -= 2;
					else {
						move = 2;
						inmove = 0;
                        waitTime = 40;
					}
				break;
				
				case 2:
					if(x<=SCREEN_W-400) x += 2;
					else {
						move = 1;
						inmove = 0;
                        waitTime = 40;
					}
				break;
			}
			
		}

};

#endif
