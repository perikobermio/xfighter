#ifndef bad_h
#define bad_h
#include "badStructs.h"

using namespace std;

class bad : public badStructs {

	public:
		void draw(SDL_Renderer *_ren, bad &b) {
			b.createBad();
			moveBad(_ren, b);
			drawBad(_ren, b);
		}
		
		
	private:
		void moveBad(SDL_Renderer *_ren, bad &b);
		void drawBad(SDL_Renderer *_ren, bad &b);
		
};

void bad::moveBad(SDL_Renderer *_ren, bad &b) {
	for(int i=0; i<b.vb1.size();i++) {
		switch(b.vb1[i].move) {
			case 1:
				b.vb1[i].y += 2;
			break;
			case 2:
				if(b.vb1[i].vx == 0) {
					double v = sqrt(2*2 + 2*2);
					b.vb1[i].vx = v * sin(70*( M_PI / 180));
					b.vb1[i].vy = v * cos(70*( M_PI / 180));
				}
				
				if(	b.vb1[i].x  + b.vb1[i].w + b.vb1[i].vx > SCREEN_W || b.vb1[i].x + b.vb1[i].vx < 0) 
					b.vb1[i].vx = b.vb1[i].vx*(-1);
				b.vb1[i].x += b.vb1[i].vx;
				b.vb1[i].y += b.vb1[i].vy;
			break;
		}
	}
}

void bad::drawBad(SDL_Renderer *_ren, bad &b) {
	for(int i=0; i<b.vb1.size();i++) {
		SDL_Rect rect = {(int)b.vb1[i].x,(int)b.vb1[i].y,b.vb1[i].w,b.vb1[i].h};
		SDL_SetRenderDrawColor(_ren, 0, 255, 0, 255 );
		SDL_RenderFillRect(_ren, &rect);
	}
}

#endif
