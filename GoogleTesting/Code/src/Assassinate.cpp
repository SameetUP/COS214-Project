#include "Assassinate.h"

Assassinate::Assassinate(int stealth, bool alive,Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"Assassinate",min,minFavour, h, hb) {
	this->alive=alive;
	this->stealth=stealth;
}

bool Assassinate::attack(Bannerman* myBannerman, Bannerman* enemyBannerman) {
	if (alive)
	{
        cout<<"You sent an assassin into the chambers of the enemy commander under the cover of night."<<endl;
		if (stealth>60)
		{
            cout<<"The assassin was successful and disposed of the enemy's commander without being seen."<<endl;
            myBannerman->increaseFavour();
			enemyKingdom->remove(enemyBannerman);
			myBannerman->increaseHP(5);
            cout<<"With the enemy at their door, some of the Preadorean soldiers decided to join the Dura troops. The rest took their oath."<<endl;
		}
		else
		{
            cout<<"The assassin was spotted and immediately executed."<<endl;
			alive=false;
		}

        list<Bannerman*> s = myKingdom->getKingdom();
        bool winner = false;
        for (list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it){
            Bannerman* a = *it;
            if (a->getFavour() >= 10){
                winner = true;
            }else{
                winner = false;
            }
        }
        if (winner == true && defectedAllies != 0){
            Bannerman* returned = Greg->restoreAlly(BookOfDura->getAlly());
            myKingdom->add(returned);
            enemyKingdom->remove(returned);
            cout<<"Old allies have heard of your gallantry and have decided to come back to Dura."<<endl;
        }

	}
	return alive;
}

Assassinate::~Assassinate(){

}
