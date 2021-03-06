#ifndef badStructs_h
#define badStructs_h

using namespace std;

class badStructs {

	public:

		struct bad1 {
			double x,y,vx,vy;
			int w,h,move;
		};
		vector<bad1> vb1;
		
		void createBad() {
			Uint32 tmp = SDL_GetTicks();
			if(tmp >= badNext) {
				if(badConfig[item].isObject() && !badConfig[item].isNull()) {
					Json::Value aBad;
					for(auto const& key : badConfig[item].getMemberNames()) {
						badNext = atoi(key.c_str()) + tmp;
						aBad = badConfig[item][key];
					}
					for(int i=0;i<aBad.size();i++) {
						if(aBad[i]["type"] == 1) {
							double  x 		= aBad[i]["x"].asDouble();
							double 	y 		= aBad[i]["y"].asDouble();
							int 	w		= aBad[i]["w"].asInt();
							int 	h		= aBad[i]["h"].asInt();
							int 	move	= aBad[i]["move"].asInt();
							vb1.push_back(bad1({x, y, 0, 0, w, h, move}));
						}
					}
					++item;
				}
			}
		}
		
		void loadConfig() {
			Json::Value root;
			Json::Reader reader;
			ifstream json("bad.json", ifstream::binary);
			reader.parse(json,root,false);
			badConfig = root;
		}
		
	private:
		
		Json::Value badConfig;
		int item = 0;
		Uint32 badNext = 3000;
};

#endif
