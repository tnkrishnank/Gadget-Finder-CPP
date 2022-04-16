//Header Files
#include "internals.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Internals :: Internals()
{
    ram = 0;
    storage = 0;
    network = "";
    os = "";
    processor = "";
}

//Function to get details related to Internals of a particular gadget
void Internals :: input(string fname)
{
    stringstream ss;
    ofstream file;

    cout << endl << "                                                        INTERNALS" << endl << endl;

    cout << "               ENTER RAM SIZE (GB)     : ";
    cin >> ram;

    cout << "               ENTER STORAGE SIZE (GB) : ";
    cin >> storage;

    fflush(stdin);

    cout << "               ENTER NETWORK DETAILS   : ";
    getline(cin,network);
    network = Utilities :: toUpper(network);

    fflush(stdin);

    cout << "               ENTER OS                : ";
    getline(cin,os);
    os = Utilities :: toUpper(os);

    fflush(stdin);

    cout << "               ENTER PROCESSOR DETAILS : ";
    getline(cin,processor);
    processor = Utilities :: toUpper(processor);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "RAM SIZE (GB)     : " << ram << " GB" << endl;
    file << "STORAGE SIZE (GB) : " << storage << " GB" << endl;
    file << "NETWORK DETAILS   : " << network << endl;
    file << "OS                : " << os << endl;
    file << "PROCESSOR DETAILS : " << processor << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Internals details from a particular gadget
void Internals :: display(string fname)
{
    cout << endl << "                                                        INTERNALS" << endl << endl;

    Utilities :: print(fname,"RAM SIZE (GB)     :");
}
