#ifndef player_h
#define player_h

using namespace std;

class player {

	public:
		struct p {
			double x=200,y=200;
			double a=0.6,vx=0,vy=0,vmax=10;
			int w=30,h=30;
		} p1;
		
		
		
		
		///////////////////////////////////////
		void move(p &ply, bool R, bool L, bool U, bool D) {
			if(R && ply.vx<=ply.vmax) {
				ply.vx += ply.a;
			} else if(ply.vx>0){
				ply.vx -= ply.a;
				if(ply.vx<0) ply.vx = 0;
			}
			
			if(L && ply.vx>=-ply.vmax) {
				ply.vx -= ply.a;
			} else if(ply.vx<0){
				ply.vx += ply.a;
				if(ply.vx>0) ply.vx = 0;
			}
			
			if(D && ply.vy<=ply.vmax) {
				ply.vy += ply.a;
			} else if(ply.vy>0){
				ply.vy -= ply.a;
				if(ply.vy<0) ply.vy = 0;
			}
			
			if(U && ply.vy>=-ply.vmax) {
				ply.vy -= ply.a;
			} else if(ply.vy<0){
				ply.vy += ply.a;
				if(ply.vy>0) ply.vy = 0;
			}
			
			ply.x += ply.vx;
			ply.y += ply.vy;
			if(ply.x<0) ply.x = 0;
			if(ply.x+ply.w>SCREEN_W) ply.x = SCREEN_W - ply.w;
			if(ply.y<0) ply.y = 0;
			if(ply.y+ply.h>SCREEN_H) ply.y = SCREEN_H - ply.h;
		}
				
		void drawPlayer(SDL_Renderer *_ren, p ply) {
			SDL_Rect rect = {(int)ply.x,(int)ply.y,ply.w,ply.h};
			SDL_RenderDrawRect(_ren, &rect);
		}

};

#endif
