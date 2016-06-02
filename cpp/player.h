#ifndef player_h
#define player_h
#include "playerStructs.h"

using namespace std;

class player : public playerStructs {

	public:
		void move(player &p, bool R, bool L, bool U, bool D) {
			movePlayer(p.p1, R, L, U, D);
			moveFire(p.vf1);
		}
		void fire(player &p, bool F);
		void draw(SDL_Renderer *_ren, player p) {
			drawPlayer(_ren, p.p1);
			drawFire(_ren, p.vf1);
		}
		
	private:
		void movePlayer(p &ply, bool R, bool L, bool U, bool D);
		void moveFire(vector<pFire1> &fire);
		
		void drawPlayer(SDL_Renderer *_ren, p ply) {
			SDL_Rect rect = {(int)ply.x,(int)ply.y,ply.w,ply.h};
			SDL_RenderDrawRect(_ren, &rect);
		}
		void drawFire(SDL_Renderer *_ren, vector<pFire1> fire) {
			for(int i=0; i<fire.size();i++) {
				SDL_Rect rect = {(int)fire[i].x,(int)fire[i].y,5,10};
				SDL_RenderDrawRect(_ren, &rect);
			}
		}
		
		void proveColision(p &ply) {
			if(ply.x<0) { 				ply.x = 0; 					ply.vx = 0; }
			if(ply.x+ply.w>SCREEN_W) { 	ply.x = SCREEN_W - ply.w;	ply.vx = 0; }
			if(ply.y<0) { 				ply.y = 0;					ply.vy = 0; }
			if(ply.y+ply.h>SCREEN_H) { 	ply.y = SCREEN_H - ply.h;	ply.vy = 0; }
		}
};


void player::movePlayer(p &ply, bool R, bool L, bool U, bool D) {
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

void player::moveFire(vector<pFire1> &fire) {
	for(int i=0; i<fire.size();i++) {
		fire[i].y -= 30;
	}
}

void player::fire(player &p, bool F) {	
	if(F) {
		Uint32 tmp = SDL_GetTicks();
		if(tmp >= p.p1.t + p.p1.cad) {
			p.createFire();
			p.p1.t = SDL_GetTicks();
		}
	}
}

#endif
