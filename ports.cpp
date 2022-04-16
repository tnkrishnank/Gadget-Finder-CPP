//Header Files
#include "ports.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Ports :: Ports()
{
    aux = false;
    hdmi = false;
    rj45 = false;
    vga = false;
    usb = false;
    typeC = false;
    nHdmi = 0;
    nUsb = 0;
}

//Function to get details related to Ports of a particular gadget
void Ports :: input(string fname)
{
    char ch;

    stringstream ss;
    ofstream file;

    cout << endl << "                                                          PORTS" << endl << endl;

    fflush(stdin);

    cout << "               IS AUX PORT AVAILABLE (Y/N)    : ";
    cin >> ch;
    aux = Utilities :: trueFalse(ch);

    fflush(stdin);

    cout << "               IS HDMI PORT AVAILABLE (Y/N)   : ";
    cin >> ch;
    hdmi = Utilities :: trueFalse(ch);

    if(hdmi)
    {
        cout << "               ENTER NUMBER OF HDMI PORTS     : ";
        cin >> nHdmi;
    }

    fflush(stdin);

    cout << "               IS RJ45 PORT AVAILABLE (Y/N)   : ";
    cin >> ch;
    rj45 = Utilities :: trueFalse(ch);

    fflush(stdin);

    cout << "               IS VGA PORT AVAILABLE (Y/N)    : ";
    cin >> ch;
    vga = Utilities :: trueFalse(ch);

    fflush(stdin);

    cout << "               IS USB PORT AVAILABLE (Y/N)    : ";
    cin >> ch;
    usb = Utilities :: trueFalse(ch);

    if(usb)
    {
        cout << "               ENTER NUMBER OF USB PORTS      : ";
        cin >> nUsb;
    }

    fflush(stdin);

    cout << "               IS TYPE-C PORT AVAILABLE (Y/N) : ";
    cin >> ch;
    typeC = Utilities :: trueFalse(ch);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "AUX                  : " << Utilities :: checkAvail(aux) << endl;

    if(hdmi)
        file << "NUMBER OF HDMI PORTS : " << nHdmi << endl;
    else
        file << "HDMI                 : " << Utilities :: checkAvail(hdmi) << endl;

    file << "RJ45                 : " << Utilities :: checkAvail(rj45) << endl;
    file << "VGA                  : " << Utilities :: checkAvail(vga) << endl;

    if(usb)
        file << "NUMBER OF USB PORTS  : " << nUsb << endl;
    else
        file << "USB                  : " << Utilities :: checkAvail(usb) << endl;

    file << "TYPE-C               : " << Utilities :: checkAvail(typeC) << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Ports details from a particular gadget
void Ports :: display(string fname)
{
    cout << endl << "                                                          PORTS" << endl << endl;

    Utilities :: print(fname,"AUX                  :");
}
