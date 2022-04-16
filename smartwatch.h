#ifndef SMARTWATCH_H
#define SMARTWATCH_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "battery.h"
#include "dimension.h"
#include "display.h"
#include "internals.h"

#include <iostream>

using namespace std;

//Class containing data of SmartWatch
//Inherited from class Electronics
class SmartWatch : public Electronics
{
    public:
        //Constructor
        SmartWatch();

        Battery battery;
        Dimension dimension;
        Display disp;
        Internals internals;

        //Data Members
        string shape;
        string strapMaterial;
        string bodyMaterial;
        bool waterProof;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // SMARTWATCH_H
