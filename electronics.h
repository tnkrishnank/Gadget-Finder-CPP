#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <iostream>

using namespace std;

//Class containing data of all Electronics
//Base class for all gadgets
class Electronics
{
    public:
        //Constructor
        Electronics();

        //Data Members
        static string fname;

        string brand;
        string model;
        float price;
        int releaseYear;
        int warranty;
        float weight;
        string colour;
        string addFeatures;

        //Member Functions
        void input(string label);
        static void display();

    protected:

    private:
};

#endif // ELECTRONICS_H
