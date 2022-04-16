#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>

using namespace std;

//Class containing data related to Dimension
class Dimension
{
    public:
        //Constructor
        Dimension();

        //Data Members
        float length;
        float breadth;
        float depth;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // DIMENSION_H
