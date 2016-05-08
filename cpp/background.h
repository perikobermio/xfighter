#ifndef background_h
#define background_h

class background {
    public:
        struct back {
            SDL_Texture* img;
            int type, x, y, w, h, v;
        };
        std::vector<back> vBack;
        
        struct backAdd {SDL_Texture* img; int w,h;};
        std::vector<backAdd> vAdd;
        

        std::vector<back> getBackgrounds(SDL_Renderer *ren) {
			int w, h;
            std::string space = "../img/space.jpg";
            SDL_Texture* tSpace = _ren.loadImages(space, ren);
            SDL_QueryTexture(tSpace, NULL, NULL, &w, &h);
            vBack.push_back(back({tSpace,0,0,0,w,h,1}));
            
            //adds
            std::string planet;
            SDL_Texture* tPlanet;
            for(int i=1;i<5;++i)  {
				planet = "../img/back/planet" + std::to_string(i) + ".png";
				tPlanet = _ren.loadImages(planet, ren);
				SDL_QueryTexture(tSpace, NULL, NULL, &w, &h);
				vAdd.push_back(backAdd({tPlanet,w,h}));
			}

            return background::vBack;
        }

        void drawBackground(SDL_Renderer *ren) {
			moveBackground();
			SDL_Rect spr = {0,0,vBack[0].w,vBack[0].h};
			SDL_Rect dst = {0,vBack[0].y,vBack[0].w,vBack[0].h};
			SDL_RenderCopy(ren, vBack[0].img, &spr, &dst);
			
			dst = {0,vBack[0].y-vBack[0].h,vBack[0].w,vBack[0].h};
			SDL_RenderCopy(ren, vBack[0].img, &spr, &dst);
			
			//draw adds
			if(!addActive && canCreateAdd(10)) {
				createAdd();
			} else if(addActive) {
				drawAdds(ren);
			}
        }

        private:
            render _ren;
            int ralentizador = 0;
            bool addActive = false;
            struct sAddActive{int i, x, y, wh, v;} saActive;

            void moveBackground() {
				if(ralentizador == 3) {
					ralentizador = 0;
					vBack[0].y += vBack[0].v;
					if(vBack[0].y >= vBack[0].h) vBack[0].y = 0;
				}
				++ralentizador;
            }
            
            
            bool canCreateAdd(int p) {
				int x = 0 + (rand() % (int)(p - 0 + 1));
				if(x == 0) return true;
				return false;
			}
			void createAdd() {
				int i = 1 + (rand() % (int)(4 - 1 + 1));
				int wh = 200 + (rand() % (int)(1000 - 200 + 1));
				int x = (-wh+5) + (rand() % (int)((SCREEN_W-5) - (-wh+5) + 1));
				int v = 2;
				if(wh>600) v=3; if(wh<400) v=1;
				
				saActive.i = i;
				saActive.x = x;
				saActive.y = -wh;
				saActive.wh = wh;
				saActive.v = v ;
				addActive = true;
			}
            void drawAdds(SDL_Renderer *ren) {
				saActive.y = saActive.y + saActive.v;
				if(saActive.y <= SCREEN_H) {
					SDL_Rect spr = {0,0,vAdd[saActive.i].w,vAdd[saActive.i].h};
					SDL_Rect dst = {saActive.x,saActive.y,saActive.wh,saActive.wh};
					SDL_RenderCopy(ren, vAdd[saActive.i].img, &spr, &dst);
				} else {
					addActive = false;
				}
			}
};

#endif
