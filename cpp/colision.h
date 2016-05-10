#ifndef colision_h
#define colision_h

class colision {
	private:
		player _player;
		badBoss _boss;

    public:
		void detectColision() {
			player::p1 player =  _player.getP1();
			std::vector<player::fire> playerFire = _player.getFire();
			
			badBoss::bBoss boss = _boss.getBoss();
			std::vector<badBoss::fire> bossFire = _boss.getFire();
		}
};

#endif
