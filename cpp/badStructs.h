#ifndef badStructs_h
#define badStructs_h

using namespace std;

class badStructs {

	public:

		struct bad1 {
			double x,y,v;
			int r;
		};
		vector<bad1> vb1;
		
		void createBad() {
			vb1.push_back(bad1({500, 500, 30, 5}));
		}
		
};

#endif
