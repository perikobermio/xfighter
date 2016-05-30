#ifndef player_h
#define player_h

class player {
    public:
        struct p1 {
            SDL_Rect spr0   = {0,   0,  87, 80};
            SDL_Rect sprR5  = {435, 0,  87, 80};
            SDL_Rect sprL5  = {435, 80, 87, 80};
            SDL_Rect aSpr;
            int fireType = 0;
            int x = 500;
            int y = 650;
            int h = 87;
            int w = 80;
            int v = 5;
            int cad = 10;
            int tmpFire = 0;
        };

        struct fire {
            int type, x, y, w, h, v;
        };
        std::vector<fire> vFire;


        p1 getP1() {
            p1 p;
            p.aSpr = p.spr0;
            return p;
        }
        
        std::vector<fire> getFire() {
            return vFire;
        }

        void moveP1(bool LEFT, bool RIGHT, bool UP, bool DOWN, player::p1 &cP1) {
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
            if(!LEFT && !RIGHT && !UP && !DOWN) {
                cP1.aSpr = cP1.spr0;
            }

            detectP1OutRange(cP1);
        }

        int createFire(player::p1 cP1) {
            int v, cad;
            switch(cP1.fireType) {
                case 0:
                    cP1.w = 3; cP1.h = 20; v = 15;
                    vFire.push_back(fire({0,cP1.x+20,cP1.y,cP1.w,cP1.h,v}));
                    vFire.push_back(fire({0,cP1.x+55,cP1.y,cP1.w,cP1.h,v}));
                break;
            }
            return 1;
        }

        void drawFires(SDL_Renderer *ren) {
            for(int i=0; i<vFire.size();i++) {
                SDL_Rect dst = {vFire[i].x, vFire[i].y, vFire[i].w, vFire[i].h};
                SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
                SDL_RenderFillRect(ren, &dst);
                moveFire(vFire[i], i);
            }
        }
        
        int cadenceControl(player::p1 &cP1, bool fire) {
			if(cP1.tmpFire != 0 && cP1.tmpFire <= cP1.cad) {
				cP1.tmpFire = cP1.tmpFire+1;
				return false;
			} else if(cP1.tmpFire == 0 && fire) {
				cP1.tmpFire = cP1.tmpFire+1;
				return true;
			} else if(cP1.tmpFire > cP1.cad) {
				cP1.tmpFire = 0;
                return false;
			}
			return false;
		}

    private:
        void moveFire(player::fire &fire, int i) {
            fire.y = fire.y - fire.v;
            detectOutRange(fire, i);
        }

        void detectOutRange(player::fire &fire, int i) {
            if(fire.y < 0 || fire.y > SCREEN_H || fire.x < 0 || fire.x > SCREEN_W) {
                vFire.erase(vFire.begin()+i);
            }
        }

        void detectP1OutRange(player::p1 &cP1) {
            if(cP1.x < 0) cP1.x = 0;
            if(cP1.x + cP1.w > SCREEN_W) cP1.x = SCREEN_W - cP1.w;
            if(cP1.y < 0) cP1.y = 0;
            if(cP1.y + cP1.h > SCREEN_H) cP1.y = SCREEN_H - cP1.h;
        }

};

#endif
