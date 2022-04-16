#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>

using namespace std;

//Class containing data related to Battery
class Battery
{
    public:
        //Constructor
        Battery();

        //Data Members
        int capacity;
        int standbyTime;
        int chargerOP;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // BATTERY_H
