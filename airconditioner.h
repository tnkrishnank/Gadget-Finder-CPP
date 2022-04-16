#ifndef AIRCONDITIONER_H
#define AIRCONDITIONER_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "dimension.h"

#include <iostream>

using namespace std;

//Class containing data of AirConditioner
//Inherited from class Electronics
class AirConditioner : public Electronics
{
    public:
        //Constructor
        AirConditioner();

        Dimension dimension;

        //Data Members
        float tonnage;
        float area;
        int energyRating;
        string compressorType;
        string type;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // AIRCONDITIONER_H
