#ifndef player_h
#define player_h
#include "playerStructs.h"

using namespace std;

class player : public playerStructs {

	public:
		void move(player &p, bool R, bool L, bool U, bool D) {
			movePlayer(p.p1, R, L, U, D);
			moveFire(p);
			outOfRange(p);
		}
		void fire(player &p, bool F);
		void changeWeapon(p &p1, int weapon) {
			p1.fireType = weapon;
		}
		void draw(SDL_Renderer *_ren, player p) {
			drawPlayer(_ren, p.p1);
			drawFire(_ren, p);
		}
		
	private:
		void movePlayer(p &ply, bool R, bool L, bool U, bool D);
		void moveFire(player &p);
		
		void drawPlayer(SDL_Renderer *_ren, p ply) {
			SDL_Rect rect = {(int)ply.x,(int)ply.y,ply.w,ply.h};
			SDL_SetRenderDrawColor(_ren, 155, 220, 255, 255 );
			SDL_RenderFillRect(_ren, &rect);
		}
		void drawFire(SDL_Renderer *_ren, player p) {
			for(int i=0; i<p.vf1.size();i++) {
				SDL_Rect rect = {(int)p.vf1[i].x,(int)p.vf1[i].y,p.vf1[i].w,p.vf1[i].h};
				SDL_SetRenderDrawColor(_ren, 255, 0, 0, 255 );
				SDL_RenderFillRect(_ren, &rect);
			}
		}
		
		void outOfRange(player &p) {
			if(p.p1.x<0) { 					p.p1.x = 0; 					p.p1.vx = 0; }
			if(p.p1.x+p.p1.w>SCREEN_W) { 	p.p1.x = SCREEN_W - p.p1.w;		p.p1.vx = 0; }
			if(p.p1.y<0) { 					p.p1.y = 0;						p.p1.vy = 0; }
			if(p.p1.y+p.p1.h>SCREEN_H) { 	p.p1.y = SCREEN_H - p.p1.h;		p.p1.vy = 0; }
			
			for(int i=0; i<p.vf1.size();i++) {
				if(p.vf1[i].y < -10) p.vf1.erase(p.vf1.begin()+i);
			}
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
}

void player::moveFire(player &p) {
	for(int i=0; i<p.vf1.size();i++) {
		p.vf1[i].y -= 30;
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
