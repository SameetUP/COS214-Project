
#include<Historian.h> //originator, has memento included
#include<HistoryBook.h> //caretaker
#include<Kingdom.h>
#include<Economy.h>
#include<HealthyState.h>
#include<FailedState.h>
#include<UnstableState.h>
#include<Commander.h>
#include<Ambush.h>
#include<BattleField.h>
#include<Siege.h>
#include<Assassinate.h>
#include<Location.h>
#include<Weather.h>
#include<Topology.h>
#include<MasterOfCoin.h>
#include<sendRaven.h>
#include<Factory.h>
#include<FoodFac.h>
#include<MedicalFac.h>
#include<WeaponsFac.h>
#include<SupplyWagon.h>
#include<FoodWagon.h>
#include<MedicalWagon.h>
#include<WeaponWagon.h>
#include<Troop.h>

#include "gtest/gtest.h"

TEST(KingdomTestSuite, Bannermen) {
    Kingdom *Dura;
    Economy *DuraEco;
    Kingdom *Preadora;
    Economy *PreadoraEco;
    bool attack = true;
    Bannerman *enemy;
    Bannerman *fighter;
    string strategy;
    State *DuraState;
    State *PreadoraState;
    WarIndicators *warind = new WarIndicators();
    Historian *Greg = new Historian();
    HistoryBook *BookOfDura = new HistoryBook();
    Treasury *tres;
    Raven *myRaven;
    State *TestState = new HealthyState();

    Economy *TestEco = new Economy(TestState, 100);

    Kingdom *TestKingdom = new Kingdom(TestEco);

    TestKingdom->add(new Commander("Stratham"));
    TestKingdom->add(new Commander("Trudid"));
    TestKingdom->add(new Commander("Mirefield"));


    list<Bannerman *> s = TestKingdom->getKingdom();


    Historian *Thom = new Historian();
    HistoryBook *Book = new HistoryBook();

    Bannerman *myBannerman = s.front();

    Thom->setAlly(myBannerman);
    Book->add(Thom->Store());

    TestKingdom->remove(myBannerman);

    EXPECT_EQ(myBannerman->getName(),"Stratham");

    Bannerman *returned = Thom->restoreAlly(Book->getAlly());
    TestKingdom->add(returned);
    EXPECT_EQ(returned->getName(),"Stratham");
}