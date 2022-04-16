//Header Files
#include "battery.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Battery :: Battery()
{
    capacity = 0;
    standbyTime = 0;
    chargerOP = 0;
}

//Function to get details related to Battery of a particular gadget
void Battery :: input(string fname)
{
    stringstream ss;
    ofstream file;

    cout << endl << "                                                         BATTERY" << endl << endl;

    cout << "               ENTER BATTERY CAPACITY (mAh) : ";
    cin >> capacity;

    cout << "               ENTER STANDBY TIME (HRS)     : ";
    cin >> standbyTime;

    cout << "               ENTER CHARGER OUTPUT (W)     : ";
    cin >> chargerOP;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "CAPACITY (mAh)     : " << capacity << " mAh" << endl;
    file << "STANDBY TIME (HRS) : " << standbyTime << " HRS" << endl;
    file << "CHARGER OUTPUT (W) : " << chargerOP << " W" << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Battery details from a particular gadget
void Battery :: display(string fname)
{
    cout << endl << "                                                         BATTERY" << endl << endl;

    Utilities :: print(fname,"CAPACITY (mAh)     :");
}
