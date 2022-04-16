#ifndef LAPTOP_H
#define LAPTOP_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "battery.h"
#include "camera.h"
#include "dimension.h"
#include "display.h"
#include "internals.h"
#include "ports.h"

#include <iostream>

using namespace std;

//Class containing data of Laptop
//Inherited from class Electronics
class Laptop : public Electronics
{
    public:
        //Constructor
        Laptop();

        Battery battery;
        Camera camera;
        Dimension dimension;
        Display disp;
        Internals internals;
        Ports ports;

        //Data Members
        int addStorage;
        bool touch;
        bool graphics;
        int ramGraphics;
        string type;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // LAPTOP_H
