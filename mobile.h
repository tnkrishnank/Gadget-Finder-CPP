#ifndef MOBILE_H
#define MOBILE_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "battery.h"
#include "camera.h"
#include "dimension.h"
#include "display.h"
#include "internals.h"

#include <iostream>

using namespace std;

//Class containing data of Mobile
//Inherited from class Electronics
class Mobile : public Electronics
{
    public:
        //Constructor
        Mobile();

        Battery battery;
        Camera camera;
        Dimension dimension;
        Display disp;
        Internals internals;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // MOBILE_H
