#ifndef playerStructs_h
#define playerStructs_h

using namespace std;

class playerStructs {

	public:
		struct p {
			double x=490,y=700;
			double a=0.3,vx=0,vy=0,vmax=10;
			int w=30,h=30,fireType=1;
			Uint32 cad = 300, t = 0;
		} p1;
	
		struct pFire1 {
			double x,y,v;
			int w,h,damage;
		};
		vector<pFire1> vf1;
		
		
		
	//creating
	void createFire() {
		switch(p1.fireType) {
			case 1: vf1.push_back(pFire1({p1.x+(p1.w/2-2), p1.y, 30, 5, 10})); break;
			case 2: 
				vf1.push_back(pFire1({p1.x, p1.y, 30, 5, 10, 2}));
				vf1.push_back(pFire1({p1.x+(p1.w-5), p1.y, 30, 5, 10, 2}));
			break;
		}
		
	}
};

#endif
