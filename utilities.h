#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

using namespace std;

//Class containing often reused functions
class Utilities
{
    public:
        //Constructor
        Utilities();

        //Member Functions
        static string toUpper(string str);
        static bool trueFalse(char ch);
        static string checkAvail(bool chk);
        static void addModel(string fname, string model);
        static void print(string fname, string str);

    protected:

    private:
};

#endif // UTILITIES_H
