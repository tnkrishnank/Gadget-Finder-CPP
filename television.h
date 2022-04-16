#ifndef TELEVISION_H
#define TELEVISION_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "dimension.h"
#include "display.h"
#include "internals.h"
#include "ports.h"

#include <iostream>

using namespace std;

//Class containing data of Television
//Inherited from class Electronics
class Television : public Electronics
{
    public:
        //Constructor
        Television();

        Dimension dimension;
        Display disp;
        Internals internals;
        Ports ports;

        //Data Members
        int type;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // TELEVISION_H
