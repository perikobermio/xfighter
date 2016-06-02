#ifndef bad_h
#define bad_h
#include "badStructs.h"

using namespace std;

class bad : public badStructs {

	public:
		void draw(SDL_Renderer *_ren, bad &b) {
			b.createBad();
			drawBad(_ren, b.vb1);
		}
		
		
	private:
		void drawBad(SDL_Renderer *_ren, vector<bad1> vb1);
		
};

void bad::drawBad(SDL_Renderer *_ren, vector<bad1> vb1) {
	
}

#endif
