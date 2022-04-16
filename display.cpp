//Header Files
#include "display.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Display :: Display()
{
    displaySize = 0.0f;
    displayType = "";
    resHeight = 0;
    resWidth = 0;
    refreshRate = 0;
    ppi = 0;
}

//Function to get details related to Display of a particular gadget
void Display :: input(string fname)
{
    stringstream ss;
    ofstream file;

    cout << endl << "                                                         DISPLAY" << endl << endl;

    cout << "               ENTER DISPLAY SIZE (inch) : ";
    cin >> displaySize;

    fflush(stdin);

    cout << "               ENTER DISPLAY TYPE        : ";
    getline(cin,displayType);
    displayType = Utilities :: toUpper(displayType);

    cout << "               ENTER HEIGHT RESOLUTION   : ";
    cin >> resHeight;

    cout << "               ENTER WIDTH RESOLUTION    : ";
    cin >> resWidth;

    cout << "               ENTER REFRESH RATE (Hz)   : ";
    cin >> refreshRate;

    cout << "               ENTER PIXEL DENSITY (ppi) : ";
    cin >> ppi;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "SIZE          : " << displaySize << " inch" << endl;
    file << "TYPE          : " << displayType << endl;
    file << "RESOLUTION    : " << resHeight << " x " << resWidth << endl;
    file << "REFRESH RATE  : " << refreshRate << " Hz" << endl;
    file << "PIXEL DENSITY : " << ppi << " ppi" << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Display details from a particular gadget
void Display :: display(string fname)
{
    cout << endl << "                                                         DISPLAY" << endl << endl;

    Utilities :: print(fname,"SIZE          :");
}
