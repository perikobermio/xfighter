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
            for(int i=0; i<vBack.size();i++) {
                SDL_Rect spr = {vBack[i].x,vBack[i].y,SCREEN_W,SCREEN_H};
                SDL_Rect dst = {0,0,SCREEN_W,SCREEN_H};
                SDL_RenderCopy(ren, vBack[i].img, &spr, &dst);
                moveBackground(i);
            }
        }

        private:
            render _ren;

            void moveBackground(int i) {
                vBack[i].y += 1;
                if(vBack[i].y >= vBack[i].h - SCREEN_H)
                    vBack[i].y = 0;
            }
};

#endif
