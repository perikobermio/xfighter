#ifndef player_h
#define player_h

using namespace std;

class player {

	public:
		struct p {
			double x=200,y=200;
			double a=0.2,v=0,vmax=10;
			int w=30,h=30;
		} p1;
		
		
		
		
		///////////////////////////////////////
		void move(p &ply, bool R, bool L, bool U, bool D, bool F) {
			if(R) {
				if(ply.v <= ply.vmax) {
					ply.v = ply.v + ply.a;
					if(ply.v > ply.vmax) ply.v = ply.vmax;
					ply.x += ply.v;
				}
			} else {
				if(ply.v >= 0) {
					ply.v = ply.v - ply.a;
					ply.x += ply.v;
				}
			}
			
			/*else {
				if(ply.v >= 0) {
					ply.v = ply.v - ply.a;
					ply.x += ply.v;
				}
			}*/
			
			
			
			/*else {
				if(ply.v >= 0) {
					ply.v = ply.v - ply.a;
					ply.x -= ply.v;
				}
			}*/
			
			
		}
				
		void drawPlayer(SDL_Renderer *_ren, p ply) {
			SDL_Rect rect = {(int)ply.x,(int)ply.y,ply.w,ply.h};
			SDL_RenderDrawRect(_ren, &rect);
		}

};

#endif
