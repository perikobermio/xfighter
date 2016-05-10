#ifndef badBoss_h
#define badBoss_h

class badBoss {
	private:
		render _ren;
		SDL_Texture* tBad;
        SDL_Texture* tShots;

        /////////////
        
        struct fireSpr {
            SDL_Rect f1 = {0,47,20,20};
        } fSpr;


    public:
		struct bBoss {
            SDL_Rect spr = {610,640,270,300};
            int x = SCREEN_W/2-200, y = -700;
            int inmove = 1, move = 0, kont = 0, waitTime = 0;
        } boss;
        struct fire {
            int type, x, y;
            float v, vx, vy;
            int angle;
        };
        std::vector<fire> vFire;
        
    
		void loadBosses(SDL_Renderer *ren) {
			std::string bad = "../img/ships/bad/badSprite.png";
            tBad = _ren.loadImages(bad, ren);

            std::string shots = "../img/shot/shots.png";
            tShots = _ren.loadImages(shots, ren);
		}
    
		void drawBoss(SDL_Renderer *ren) {
            if(boss.inmove) bossMovements(boss.move);
			else {
                ++boss.kont;
                if(boss.kont>=boss.waitTime) {
                    boss.inmove = 1;
                    boss.kont = 0;
				}
			}
			
            SDL_Rect dst = {boss.x,boss.y,400,550};
            SDL_RenderCopy(ren, tBad, &boss.spr, &dst);
            drawFires(ren);
		}
		
		bBoss getBoss() {
			return boss;
		}
		std::vector<fire> getFire() {
			return vFire;
		}
		
    private:

        void drawFires(SDL_Renderer *ren) {
            for(int i=0; i<vFire.size();i++) {
				if(vFire[i].x + fSpr.f1.w > SCREEN_W || vFire[i].y + fSpr.f1.h > SCREEN_H) 
					vFire.erase(vFire.begin()+i);
				
                float x2 = vFire[i].x + vFire[i].vx;
                float y2 = vFire[i].y + vFire[i].vy;
                vFire[i].x = (int)x2;
                vFire[i].y = (int)y2;

                SDL_Rect dst = {(int)x2,(int)y2,fSpr.f1.w,fSpr.f1.h};
                SDL_RenderCopy(ren, tShots, &fSpr.f1, &dst);
            }
        }
       
		void bossMovements(int muf) {
			switch(muf) {
				case 0:
                    if(boss.y<-150) boss.y += 1;
					else {
                        boss.move = 1;
                        boss.inmove = 0;
                        boss.waitTime = 120;
                        bossFires(0);
					}
				break;
				
				case 1:
                    if(boss.x>=0) boss.x -= 2;
					else {
                        boss.move = 2;
                        boss.inmove = 0;
                        boss.waitTime = 40;
                        bossFires(0);
					}
				break;
				
				case 2:
                    if(boss.x<=SCREEN_W-400) boss.x += 2;
					else {
                        boss.move = 1;
                        boss.inmove = 0;
                        boss.waitTime = 40;
                        bossFires(0);
					}
				break;
			}
			
		}

        void bossFires(int type) {
            switch(type) {
                case 0:
                    int x = boss.x + (boss.spr.w/2);
                    int y = boss.y + boss.spr.h;

                    vFire.push_back(fire({0,x,y,7,7,0,20}));
                    vFire.push_back(fire({0,x,y,7,7,0,40}));
                    vFire.push_back(fire({0,x,y,7,7,0,60}));
                    vFire.push_back(fire({0,x,y,7,7,0,80}));
                    vFire.push_back(fire({0,x,y,7,7,0,100}));
                    vFire.push_back(fire({0,x,y,7,7,0,120}));
                    vFire.push_back(fire({0,x,y,7,7,0,140}));
                    vFire.push_back(fire({0,x,y,7,7,0,160}));

                    for(int i=0; i<vFire.size();i++) {
                        vFire[i].v = sqrt(vFire[i].vx*vFire[i].vx + vFire[i].vy*vFire[i].vy);
                        vFire[i].vy = vFire[i].v * sin(vFire[i].angle*( M_PI / 180));
                        vFire[i].vx = vFire[i].v * cos(vFire[i].angle*( M_PI / 180));
                    }
                break;
            }

        }

};

#endif
