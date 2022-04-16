//Header Files
#include "airconditioner.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
AirConditioner :: AirConditioner()
{
    tonnage = 0.0f;
    area = 0.0;
    energyRating = 0;
    compressorType = "";
    type = "";
}

//Function to get details related to AirConditioner
void AirConditioner :: input()
{
    system("cls");

    stringstream ss;
    ofstream file;

    cout << endl << endl;
    cout << "               ******************************************************************************************\n";
    cout << "               *                                     AIR CONDITIONER                                    *\n";
    cout << "               ******************************************************************************************\n";

    cout << endl << "                                                         GENERAL" << endl << endl;

    Electronics :: input("A ");

    cout << endl;

    cout << "               ENTER TONNAGE           : ";
    cin >> tonnage;

    cout << "               ENTER AREA (SQ. FEETS)  : ";
    cin >> area;

    cout << "               ENTER ENERGY RATING     : ";
    cin >> energyRating;

    fflush(stdin);

    cout << "               ENTER COMPRESSOR TYPE   : ";
    getline(cin,compressorType);
    compressorType = Utilities :: toUpper(compressorType);

    fflush(stdin);

    cout << "               ENTER AC TYPE           : ";
    getline(cin,type);
    type = Utilities :: toUpper(type);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "TONNAGE           : " << tonnage << " TON" << endl;
    file << "AREA              : " << area << " SQ. FEETS" << endl;
    file << "ENERGY RATING     : " << energyRating << " STAR" << endl;
    file << "COMPRESSOR TYPE   : " << compressorType << endl;
    file << "AC TYPE           : " << type << endl;
    file << endl;

    file.close();

    dimension.input(fname);

    Utilities :: addModel("GAD AIR CONDITIONER.txt",model);
}

//Function to fetch and display details from a particular AirConditioner model
void AirConditioner :: display(string model)
{
    system("cls");

    stringstream ss;
    ifstream file;

    ss << "A " << model << ".txt";
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
        cout << "               *                                     AIR CONDITIONER                                    *\n";
        cout << "               ******************************************************************************************\n";

        cout << endl << "                                                         GENERAL" << endl << endl;

        Electronics :: display();

        cout << endl;

        Utilities :: print(fname,"TONNAGE           :");

        Dimension :: display(fname);
    }

    file.close();
}
