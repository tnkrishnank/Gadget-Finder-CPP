//Header files
#include "utilities.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

//Constructor
Utilities::Utilities()
{

}

//Function to convert string to uppercase
string Utilities :: toUpper(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

//Function to return true or false based on input character
bool Utilities :: trueFalse(char ch)
{
    if(ch == 'y' || ch == 'Y')
        return true;

    return false;
}

//Function to return Availability based on input
string Utilities :: checkAvail(bool chk)
{
    if(chk)
        return "AVAILABLE";

    return "NOT AVAILABLE";
}

//Function to add model number to the gadget file
void Utilities :: addModel(string fname, string model)
{
    stringstream ss;
    ofstream file;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << model << endl;

    file.close();
}

//Function to print a selected set of block
void Utilities :: print(string fname, string str)
{
    stringstream ss;
    ifstream file;

    int i = 1;
    string line;

    ss << fname;
    file.open(ss.str());
    fname = ss.str();

    while(getline(file,line))
    {
        if(i != 1 && line == "")
            break;

        if(line.find(str) != string::npos)
            i++;

        if(i > 1)
            cout << "               " << line << endl;
    }

    file.close();
}
