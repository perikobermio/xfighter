#ifndef background_h
#define background_h

class background {
    public:
        struct back {
            SDL_Texture* img;
            int type, x, y, w, h, v;
        };
        std::vector<back> vBack;


        std::vector<back> getBackgrounds(SDL_Renderer *ren) {
            std::string space = "../img/space.jpg";
            SDL_Texture* tSpace = _ren.loadImages(space, ren);
            int w, h;
            SDL_QueryTexture(tSpace, NULL, NULL, &w, &h);
            vBack.push_back(back({tSpace,0,0,0,w,h,1}));

            return background::vBack;
        }

        void drawBackground(SDL_Renderer *ren) {
			moveBackground();
			SDL_Rect spr = {0,0,vBack[0].w,vBack[0].h};
			SDL_Rect dst = {0,vBack[0].y,vBack[0].w,vBack[0].h};
			SDL_RenderCopy(ren, vBack[0].img, &spr, &dst);
			
			spr = {0,0,vBack[0].w,vBack[0].h};
			dst = {0,vBack[0].y-vBack[0].h,vBack[0].w,vBack[0].h};
			SDL_RenderCopy(ren, vBack[0].img, &spr, &dst);
    
        }

        private:
            render _ren;
            int ralentizador = 0;

            void moveBackground() {
				if(ralentizador == 3) {
					ralentizador = 0;
					vBack[0].y += vBack[0].v;
					if(vBack[0].y >= vBack[0].h) vBack[0].y = 0;
				}
				++ralentizador;
            }
};

#endif
