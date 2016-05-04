#ifndef player_h
#define player_h

class player {
    private:


    public:
        struct p1 {
            SDL_Rect spr0   = {0, 0, 87, 80};
            SDL_Rect sprR5  = {435, 0, 87, 80};
            SDL_Rect sprL5  = {435, 80, 87, 80};
            SDL_Rect aSpr;
            int x = 500;
            int y = 650;
            int h = 87;
            int w = 80;
            int v = 5;
        };

        p1 getP1() {
            p1 p;
            p.aSpr = p.spr0;
            return p;
        }
};

#endif
