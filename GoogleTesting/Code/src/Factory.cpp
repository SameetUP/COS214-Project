#include "Factory.h"
using namespace std;
void Factory::operation() {
    supply=make();
}

ArmySupplies* Factory::getSupply() {
    return supply;
}

Factory::~Factory() {

}

/*#include "Factory.h"
#include "FoodFac.h"
#include "MedicalFac.h"
#include "WeaponsFac.h"
#include "SupplyWagon.h"
#include "FoodWagon.h"
#include "MedicalWagon.h"
#include "WeaponWagon.h"

int main(){
    Factory* myFactory1 = new FoodFac();
    Factory* myFactory2 = new MedicalFac();
    Factory* myFactory3 = new WeaponsFac();

    myFactory1->operation();
    myFactory2->operation();
    myFactory3->operation();

    SupplyWagon* OriginalFoodWagon = new FoodWagon();
    SupplyWagon* OriginalMedicalWagon = new MedicalWagon();
    SupplyWagon* OriginalWeaponWagon = new WeaponWagon();

    OriginalFoodWagon->setSup(myFactory1->getSupply());
    OriginalMedicalWagon->setSup(myFactory2->getSupply());
    OriginalWeaponWagon->setSup(myFactory3->getSupply());

    SupplyWagon* Foodwagons[5];
    SupplyWagon* Medicalwagons[5];
    SupplyWagon* Weaponwagons[5];
//////////////////////////////////////////////////////////////////////////////////////////////////
    for(int i =0; i<5;i++){
        Foodwagons[i]=OriginalFoodWagon->clone();
    }
    for(int i =0; i<5;i++){
        Medicalwagons[i]=OriginalMedicalWagon->clone();
    } for(int i =0; i<5;i++){
        Weaponwagons[i]=OriginalWeaponWagon->clone();
    }

    for(int i =0; i<5;i++){
        cout<<"Food Wagon "<<(i+1)<<": "<<Foodwagons[i]->getSupplies()->getAmount()<<endl;
    }
    for(int i =0; i<5;i++){
        cout<<"Medical Wagon "<<(i+1)<<": "<<Medicalwagons[i]->getSupplies()->getAmount()<<endl;
    } for(int i =0; i<5;i++){
        cout<<"Weapon Wagon "<<(i+1)<<": "<<Weaponwagons[i]->getSupplies()->getAmount()<<endl;
    }

    for(int i =0; i<5;i++){
        delete Foodwagons[i];
    }
    for(int i =0; i<5;i++){
        delete Medicalwagons[i];
    }
    for(int i =0; i<5;i++){
        delete Weaponwagons[i];
    }

    delete myFactory1;
    delete myFactory2;
    delete myFactory3;

    return 0;
}*/