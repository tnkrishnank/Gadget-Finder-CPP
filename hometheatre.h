#ifndef HOMETHEATRE_H
#define HOMETHEATRE_H

//Adding header files needed for this gadget
#include "electronics.h"
#include "dimension.h"

#include <iostream>

using namespace std;

//Class containing data of HomeTheatre
//Inherited from class Electronics
class HomeTheatre : public Electronics
{
    public:
        //Constructor
        HomeTheatre();

        Dimension dimension;

        //Data Members
        float channel;
        int nSpeaker;
        int output;

        //Member Functions
        void input();
        static void display(string model);

    protected:

    private:
};

#endif // HOMETHEATRE_H
