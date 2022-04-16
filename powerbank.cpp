//Header Files
#include "powerbank.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
PowerBank :: PowerBank()
{
    nTypeC = 0;
    nUsb = 0;
    output = 0;
}

//Function to get details related to PowerBank
void PowerBank :: input()
{
    system("cls");

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                       POWER BANK                                       *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("P ");

    cout << endl;

    cout << "               ENTER NUMBER OF TYPE-C PORTS : ";
    cin >> nTypeC;

    cout << "               ENTER NUMBER OF USB PORTS    : ";
    cin >> nUsb;

    cout << "               ENTER OUTPUT (W)             : ";
    cin >> output;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "NUMBER OF TYPE-C PORTS : " << nTypeC << endl;
    file << "NUMBER OF USB PORTS    : " << nUsb << endl;
    file << "OUTPUT                 : " << output << " W" << endl;
    file << endl;

    file.close();

    battery.input(fname);
    dimension.input(fname);

    Utilities :: addModel("GAD POWER BANK.txt",model);
}

//Function to fetch and display details from a particular PowerBank model
void PowerBank :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "P " << model << ".txt";
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
        cout << "               *                                       POWER BANK                                       *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"NUMBER OF TYPE-C PORTS :");

        Battery :: display(fname);
        Dimension :: display(fname);
    }

    file.close();
}
