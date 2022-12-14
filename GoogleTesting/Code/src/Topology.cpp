#include "Topology.h"


Topology::Topology(WarTheatre* myTheatre) : Conditions(myTheatre) {
}

void Topology::setTopology()
{
    switch (getVenue())
    {
        case 'a':
            cout << "The battle is at an open war field" << endl;
            setDifficulty(getDifficulty()+2);
            break;
        case 'b' :
            cout << "The battle is at the enemy's fortress" << endl; //you can use getEnemyBannerman() to get their name for this
            setDifficulty(getDifficulty()+4);
            break;
        case 'c':
            cout << "The battle is at the enemy campsite" << endl; //look @ above comment
            setDifficulty(getDifficulty()+3);
            break;
        case 'd':
            cout << "The battle is at the enemy castle" << endl; //look at above comment
            setDifficulty(getDifficulty()+5);
            break;
    }
}

void Topology::sendScout()  {
    setTopology();
}
