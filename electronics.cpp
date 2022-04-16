//Header Files
#include "electronics.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Electronics::Electronics()
{
    brand = "";
    model = "";
    price = 0.0f;
    releaseYear = 0;
    warranty = 0;
    weight = 0;
    colour = "";
    addFeatures = "";
}

//Function to get common details of all gadgets
void Electronics :: input(string label)
{
    stringstream ss;
    ofstream file;

    fflush(stdin);

    cout << "               ENTER BRAND               : ";
    getline(cin,brand);
    brand = Utilities :: toUpper(brand);

    fflush(stdin);

    cout << "               ENTER MODEL               : ";
    getline(cin,model);
    model = Utilities :: toUpper(model);

    cout << "               ENTER PRICE               : Rs. ";
    cin >> price;

    cout << "               ENTER RELEASE YEAR        : ";
    cin >> releaseYear;

    cout << "               ENTER WARRANTY (YEARS)    : ";
    cin >> warranty;

    cout << "               ENTER WEIGHT (kg)         : ";
    cin >> weight;

    fflush(stdin);

    cout << "               ENTER COLOURS AVAILABLE   : ";
    getline(cin,colour);
    colour = Utilities :: toUpper(colour);

    fflush(stdin);

    cout << "               ENTER ADDITIONAL FEATURES : ";
    getline(cin,addFeatures);
    addFeatures = Utilities :: toUpper(addFeatures);

    ss << label << model << ".txt";
    file.open(ss.str());
    fname = ss.str();

    file << "BRAND               : " << brand << endl;
    file << "MODEL               : " << model << endl;
    file << "PRICE               : Rs. " << price << endl;
    file << "RELEASE YEAR        : " << releaseYear << endl;
    file << "WARRANTY            : " << warranty << " YEARS" << endl;
    file << "WEIGHT              : " << weight << " kg" << endl;
    file << "COLOURS             : " << colour << endl;
    file << "ADDITIONAL FEATURES : " << addFeatures << endl;
    file << endl;

    file.close();
}

//Function to fetch and display common details of a particular gadget
void Electronics :: display()
{
    stringstream ss;
    ifstream file;

    string line;

    ss << fname;
    file.open(ss.str());
    fname = ss.str();

    while(getline(file,line))
    {
        if(line == "")
            break;

        cout << "               " << line << endl;
    }

    file.close();
}

//Initializing static variable
string Electronics :: fname = "";
