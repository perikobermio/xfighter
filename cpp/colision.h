#ifndef colision_h
#define colision_h

class colision {
	private:

        int testColision(SDL_Rect a , SDL_Rect b) {
            if(b.x + b.w < a.x)	return 0;
            if(b.x > a.x + a.w)	return 0;

            if(b.y + b.h < a.y)	return 0;
            if(b.y > a.y + a.h)	return 0;

            return 1;
        }

    public:
		int detectColision(badBoss &_boss, player &_player, player::p1 cP1) {
			int tocado = 0;
            for(int i=0; i<_boss.vFire.size();i++) {
                int tc = testColision(SDL_Rect {cP1.x, cP1.y, cP1.w, cP1.h},
                                      SDL_Rect {_boss.vFire[i].x, _boss.vFire[i].y, 20, 20});
                if(tc) {
                    //_boss.destroyFire(i);
                    _boss.vFire.erase(_boss.vFire.begin()+i);
                    tocado = 1;
                }
            }
            return tocado;
		}
};

#endif
