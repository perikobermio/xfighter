#ifndef player_h
#define player_h

using namespace std;

class player {

	public:
		struct p {
			double x=200,y=200;
			double a=0.2,vx=0,vy=0,vmax=10;
			int w=30,h=30,fireType=1;
			Uint32 cad = 1000, t = SDL_GetTicks();
		} p1;
		
		struct fire {
			double x,y;
			double vx=0,vy=0,vmax;
		};
		vector<fire> vFire;
		
		
		void move(p &ply, bool R, bool L, bool U, bool D);
		void fire(player &p, bool F);
		///////////////////////////////////////
				
		void drawPlayer(SDL_Renderer *_ren, p ply) {
			SDL_Rect rect = {(int)ply.x,(int)ply.y,ply.w,ply.h};
			SDL_RenderDrawRect(_ren, &rect);
		}
		
		private:
			
			void proveColision(p &ply) {
				if(ply.x<0) { 				ply.x = 0; 					ply.vx = 0; }
				if(ply.x+ply.w>SCREEN_W) { 	ply.x = SCREEN_W - ply.w;	ply.vx = 0; }
				if(ply.y<0) { 				ply.y = 0;					ply.vy = 0; }
				if(ply.y+ply.h>SCREEN_H) { 	ply.y = SCREEN_H - ply.h;	ply.vy = 0; }
			}
};



void player::move(p &ply, bool R, bool L, bool U, bool D) {
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
	
	proveColision(ply);
}

void player::fire(player &p, bool F) {
	p.p1.tmpCad = SDL_GetTicks();
	cout << p.p1.tmpCad << endl;
	if(F) {
		cout << "---------" << endl;
		p.p1.tmpCad = 0;
	}
}

#endif
