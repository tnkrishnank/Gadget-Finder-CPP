#ifndef PORTS_H
#define PORTS_H

#include <iostream>

using namespace std;

//Class containing data related to Ports
class Ports
{
    public:
        //Constructor
        Ports();

        //Data Members
        bool aux;
        bool hdmi;
        bool rj45;
        bool vga;
        bool usb;
        bool typeC;
        int nHdmi;
        int nUsb;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // PORTS_H
