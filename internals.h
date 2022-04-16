#ifndef INTERNALS_H
#define INTERNALS_H

#include <iostream>

using namespace std;

//Class containing data related to Internals
class Internals
{
    public:
        //Constructor
        Internals();

        //Data Members
        int ram;
        int storage;
        string network;
        string os;
        string processor;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // INTERNALS_H
