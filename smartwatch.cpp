//Header Files
#include "smartwatch.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
SmartWatch :: SmartWatch()
{
    shape = "";
    strapMaterial = "";
    bodyMaterial = "";
    waterProof = false;
}

//Function to get details related to SmartWatch
void SmartWatch :: input()
{
    system("cls");

    char ch;

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                       SMART WATCH                                      *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("S ");

    cout << endl;

    fflush(stdin);

    cout << "               ENTER SHAPE             : ";
    getline(cin,shape);
    shape = Utilities :: toUpper(shape);

    fflush(stdin);

    cout << "               ENTER STRAP MATERIAL    : ";
    getline(cin,strapMaterial);
    strapMaterial = Utilities :: toUpper(strapMaterial);

    fflush(stdin);

    cout << "               ENTER BODY MATERIAL     : ";
    getline(cin,bodyMaterial);
    bodyMaterial = Utilities :: toUpper(bodyMaterial);

    fflush(stdin);

    cout << "               IS IT WATER PROOF (Y/N) : ";
    cin >> ch;
    waterProof = Utilities :: trueFalse(ch);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "SHAPE          : " << shape << endl;
    file << "STRAP MATERIAL : " << strapMaterial << endl;
    file << "BODY MATERIAL  : " << bodyMaterial << endl;
    file << "WATER PROOF    : " << Utilities :: checkAvail(waterProof) << endl;
    file << endl;

    file.close();

    battery.input(fname);
    dimension.input(fname);
    disp.input(fname);
    internals.input(fname);

    Utilities :: addModel("GAD SMART WATCH.txt",model);
}

//Function to fetch and display details from a particular SmartWatch model
void SmartWatch :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "S " << model << ".txt";
    file.open(ss.str());
    fname = ss.str();

    if(!file.is_open())
    {
        cout << endl << endl;
        cout << "               ******************************************************************************************\n";
        cout << "               *                                   FILE NOT FOUND !!!                                   *\n";
        cout << "               ******************************************************************************************\n";
    }
    else
    {
        cout << endl << endl;
        cout << "               ******************************************************************************************\n";
        cout << "               *                                       SMART WATCH                                      *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"SHAPE          :");

        Battery :: display(fname);
        Dimension :: display(fname);
        Display :: display(fname);
        Internals :: display(fname);
    }

    file.close();
}
