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
        };

        struct fire {
            int type, x, y, w, h, v, cad;
        };
        std::vector<fire> vFire;


        p1 getP1() {
            p1 p;
            p.aSpr = p.spr0;
            return p;
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

        void createFire(int type, int x, int y, int w, int h) {
            int v, cad;
            switch(type) {
                case 0:
                    w = 3; h = 20; v = 15; cad = 2;
                    vFire.push_back(fire({type,x+20,y,w,h,v,cad}));
                    vFire.push_back(fire({type,x+55,y,w,h,v,cad}));
                break;
            }
        }

        void drawFires(SDL_Renderer *ren) {
            for(int i=0; i<vFire.size();i++) {
                SDL_Rect dst = {vFire[i].x, vFire[i].y, vFire[i].w, vFire[i].h};
                SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
                SDL_RenderFillRect(ren, &dst);
                moveFire(vFire[i], i);
            }
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

        }

};

#endif
