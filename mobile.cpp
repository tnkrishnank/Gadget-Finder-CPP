//Header Files
#include "mobile.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Mobile :: Mobile()
{

}

//Function to get details related to Mobile
void Mobile :: input()
{
    system("cls");

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                         MOBILE                                         *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("M ");

    cout << endl;

    battery.input(fname);
    camera.input(fname);
    dimension.input(fname);
    disp.input(fname);
    internals.input(fname);

    Utilities :: addModel("GAD MOBILE.txt",model);
}

//Function to fetch and display details from a particular Mobile model
void Mobile :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "M " << model << ".txt";
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
        cout << "               *                                         MOBILE                                         *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Battery :: display(fname);
        Camera :: display(fname);
        Dimension :: display(fname);
        Display :: display(fname);
        Internals :: display(fname);
    }

    file.close();
}
