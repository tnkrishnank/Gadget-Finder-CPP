#ifndef POWERBANK_H
#define POWERBANK_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "battery.h"
#include "dimension.h"

#include <iostream>

using namespace std;

//Class containing data of PowerBank
//Inherited from class Electronics
class PowerBank : public Electronics
{
    public:
        //Constructor
        PowerBank();

        Battery battery;
        Dimension dimension;

        //Data Members
        int nTypeC;
        int nUsb;
        int output;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // POWERBANK_H
