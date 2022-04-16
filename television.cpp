//Header Files
#include "television.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Television::Television()
{
    type = 1;
}

//Function to get details related to Television
void Television :: input()
{
    system("cls");

    string ch;

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                       TELEVISION                                       *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("T ");

    cout << endl;

    cout << "               TYPES                  : 1. SMART TV" << endl;
    cout << "                                        2. ANDROID TV" << endl;

    cout << "               ENTER TYPE             : ";
    cin >> type;

    if(type == 2)
        ch = "ANDROID TV";
    else
    {
        type = 1;
        ch = "SMART TV";
    }

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "TYPE : " << ch << endl;
    file << endl;

    file.close();

    dimension.input(fname);
    disp.input(fname);

    if(type == 2)
        internals.input(fname);

    ports.input(fname);

    Utilities :: addModel("GAD TELEVISION.txt",model);
}

//Function to fetch and display details from a particular Television model
void Television :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    int i = 1;
    string ch;
    string line;

    ss << "T " << model << ".txt";
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
        cout << "               *                                       TELEVISION                                       *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"TYPE :");

        while(getline(file,line))
        {
            if(i != 1 && line == "")
                break;

            if(line.find("ANDROID TV") != string::npos)
                i++;

            if(i > 1)
                ch = line;
        }

        Dimension :: display(fname);
        Display :: display(fname);

        if(ch == "TYPE : ANDROID TV")
            Internals :: display(fname);

        Ports :: display(fname);
    }

    file.close();
}
