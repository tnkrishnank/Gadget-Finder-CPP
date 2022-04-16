#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

using namespace std;

//Class containing data related to Display
class Display
{
    public:
        //Constructor
        Display();

        //Data Members
        float displaySize;
        string displayType;
        int resHeight;
        int resWidth;
        int refreshRate;
        int ppi;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // DISPLAY_H
