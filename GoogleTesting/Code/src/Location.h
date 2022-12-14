#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include "WarTheatre.h"
#include "Conditions.h" //causes circular dependency?

using namespace std;

/** @brief concrete object.
 * This is the class/object that will be decorated. Inherits from WarTheatre class
 *  @author Keabetswe Mothapo
 * @date October 2022
 */

class Location : public WarTheatre {


public:

    /** @brief Default constructor.*/
	Location();

    /** @brief the function that will be called to decorate the war venue*/
	void sendScout();


};

#endif
