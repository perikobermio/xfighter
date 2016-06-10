#ifndef collision_h
#define collision_h

using namespace std;

class collision {

	public:
		void detect(player &p, bad &b) {
			for(int i=0;i<p.vf1.size();i++) {
				for(int a=0;a<b.vb1.size();a++) {
					if(detectRectCollision(p, b, i, a))
						cout << "ñapu" << endl;
				}
			}
		}
		
	private:
		bool detectRectCollision(player p, bad b, int i, int a);
};

bool collision::detectRectCollision(player p, bad b, int i, int a) {
	p.vf1[i];
	b.vb1[a];
}

#endif
