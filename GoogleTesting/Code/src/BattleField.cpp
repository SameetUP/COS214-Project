#include "BattleField.h"

BattleField::BattleField(Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"BattleField",min,minFavour, h, hb){}

bool BattleField::attack(Bannerman* myBannerman, Bannerman* enemyBannerman) {
	while (myBannerman->getHP()>0&&enemyBannerman->getHP()>0)
	{
        cout<<"You face your foe on the battlefield!"<<endl;
		//getDamage is how much damage the bannerman can inflict
		enemyBannerman->receiveDamage(myBannerman->getDamage());
        cout<<"You deal "<<myBannerman->getDamage()<<" damage to the enemy. Enemy HP:"<<enemyBannerman->getHP()<<endl;
		if ((enemyBannerman->getFood()+enemyBannerman->getMedical())<0)
		{
			enemyBannerman->receiveDamage(myBannerman->getDamage());
            cout<<"The enemy's supplies are low! They take extra damage. Enemy HP:"<<enemyBannerman->getHP()<<endl;
		} else {
			enemyBannerman->decreaseMedical();
			enemyBannerman->decreaseFood();
		}
		myBannerman->decreaseWeapons();
		
		myBannerman->receiveDamage(enemyBannerman->getDamage());
        cout<<"The enemy delivers their blow! The bannerman from "<<myBannerman->getName()<<" takes "<<enemyBannerman->getDamage()<<" damage. Our HP: "<<myBannerman->getHP()<<endl;
		if ((myBannerman->getFood()+myBannerman->getMedical())<0)
		{
			myBannerman->receiveDamage(enemyBannerman->getDamage());
            cout<<"Our supplies are low! We take extra damage. Enemy HP:"<<myBannerman->getHP()<<endl;
		} else {
			myBannerman->decreaseMedical();
			myBannerman->decreaseFood();
		}
		enemyBannerman->decreaseWeapons();
	}
	
	if (myBannerman->getHP()>0&&enemyBannerman->getHP()<=0)
	{
		if(myBannerman->getFood()>enemyBannerman->getFood()){
			myBannerman->increaseFavour();
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
                cout<<returned->getName()<<"'s commander asks yor forgiveness and joins your fight once again."<<endl;
            }
		}
		else
		{
			myBannerman->decreaseFavour();
			if (myBannerman->getFavour()<minFavour) //Bannerman defects
			{
				//save defected bannemen
				Greg->setAlly(myBannerman);
				BookOfDura->add(Greg->Store());
				defectedAllies++;
				//add a remove(Bannerman* myBannerman) and add(Bannerman* myBannerman) method to 
				//remove/add a particular bannerman 
				myKingdom->remove(myBannerman);
				//tell thapelo to add id attribute and a getter, we must
				//formulate a way to make bannerman ids unique
				enemyKingdom->add(myBannerman);
                cout<<"The commanders are losing faith in your cause. "<<myBannerman->getName()<<" has defected to the other side."<<endl;
				return false;
			}
			
		}
		if (myBannerman->getWeapons()<=minSupplies)
		{
			//tell sameet to add pointer asterisk in treasury class's notify
            cout<<"The fight has ended. The commander took inventory of the supplies and sends for more."<<endl;
			m->notify(this);
		}
		enemyKingdom->remove(enemyBannerman);
        cout<<"The enemy kingdom's bannerman has been defeated. "<<enemyBannerman->getName()<<" is now under your kingdom's rule."<<endl;
		return true;
	}
	else if (myBannerman->getHP()<=0&&enemyBannerman->getHP()>0)
	{
		myKingdom->remove(myBannerman);
        cout<<myBannerman->getName()<<" fought bravely in the name of Dura. They were sadly lost in the battle."<<endl;
		return false;
	}
	else
	{
		return false;
	}
	
}

BattleField::~BattleField(){
	
}
