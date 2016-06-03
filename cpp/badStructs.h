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
			vb1.push_back(bad1({500, 500, 10, 10, 1}));
		}
		
		void loadConfig() {
			Json::Value root;
			Json::Reader reader;
			ifstream json("bad.json", ifstream::binary);
			reader.parse(json,root,false);
			cout << root;
		}
		
};

#endif
