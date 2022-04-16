//Header Files
#include "laptop.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Laptop :: Laptop()
{
    addStorage = 0;
    touch = false;
    graphics = false;
    ramGraphics = 0;
    type = "";
}

//Function to get details related to Laptop
void Laptop :: input()
{
    system("cls");

    char ch;

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                         LAPTOP                                         *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("L ");

    cout << endl;

    cout << "               ENTER ADDITIONAL STORAGE SIZE (GB) : ";
    cin >> addStorage;

    fflush(stdin);

    cout << "               IS TOUCH SCREEN AVAILABLE (Y/N)    : ";
    cin >> ch;
    touch = Utilities :: trueFalse(ch);

    fflush(stdin);

    cout << "               IS GRAPHICS CARD AVAILABLE (Y/N)   : ";
    cin >> ch;
    graphics = Utilities :: trueFalse(ch);

    if(graphics)
    {
        cout << "               ENTER GRAPHICS MEMORY SIZE (GB)    : ";
        cin >> ramGraphics;
    }

    fflush(stdin);

    cout << "               ENTER LAPTOP TYPE                  : ";
    getline(cin,type);
    type = Utilities :: toUpper(type);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "ADDITIONAL STORAGE   : " << addStorage << " GB" << endl;
    file << "TOUCH SCREEN         : " << Utilities :: checkAvail(touch) << endl;

    if(graphics)
        file << "GRAPHICS MEMORY SIZE : " << ramGraphics << " GB" << endl;
    else
        file << "GRAPHICS CARD        : " << Utilities :: checkAvail(graphics) << endl;

    file << "TYPE                 : " << type << endl;
    file << endl;

    file.close();

    battery.input(fname);
    camera.input(fname);
    dimension.input(fname);
    disp.input(fname);
    internals.input(fname);
    ports.input(fname);

    Utilities :: addModel("GAD LAPTOP.txt",model);
}

//Function to fetch and display details from a particular Laptop model
void Laptop :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "L " << model << ".txt";
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
        cout << "               *                                         LAPTOP                                         *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"ADDITIONAL STORAGE   :");

        Battery :: display(fname);
        Camera :: display(fname);
        Dimension :: display(fname);
        Display :: display(fname);
        Internals :: display(fname);
        Ports :: display(fname);
    }

    file.close();
}
