#ifndef badStructs_h
#define badStructs_h

using namespace std;

class badStructs {

	public:

		struct bad1 {
			double x,y;
			int w,h,movements;
		};
		vector<bad1> vb1;
		
		void createBad() {
			//vb1.push_back(bad1({500, 500, 10, 10, 1}));
			
			Uint32 tmp = SDL_GetTicks();
			if(tmp >= badNext) {
				if(badConfig[item].isObject() && !badConfig[item].isNull()) {
					for (auto const& id : badConfig[item].getMemberNames()) {
						int a = atoi(id);
						cout << (string)id << endl;
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
		Uint32 badNext = 2000;
};

#endif
