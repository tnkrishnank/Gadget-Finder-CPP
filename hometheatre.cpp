//Header Files
#include "hometheatre.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
HomeTheatre :: HomeTheatre()
{
    channel = 0.0f;
    nSpeaker = 0;
    output = 0;
}

//Function to get details related to HomeTheatre
void HomeTheatre :: input()
{
    system("cls");

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                      HOME THEATRE                                      *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("H ");

    cout << endl;

    cout << "               ENTER CHANNEL            : ";
    cin >> channel;

    cout << "               ENTER NUMBER OF SPEAKERS : ";
    cin >> nSpeaker;

    cout << "               ENTER OUTPUT (W)         : ";
    cin >> output;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "CHANNEL            : " << channel << endl;
    file << "NUMBER OF SPEAKERS : " << nSpeaker << endl;
    file << "OUTPUT             : " << output << " W" << endl;
    file << endl;

    file.close();

    dimension.input(fname);

    Utilities :: addModel("GAD HOME THEATRE.txt",model);
}

//Function to fetch and display details from a particular HomeTheatre model
void HomeTheatre :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "H " << model << ".txt";
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
        cout << "               *                                      HOME THEATRE                                      *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"CHANNEL            :");

        Dimension :: display(fname);
    }

    file.close();
}
