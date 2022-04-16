//Header Files
#include "dimension.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Dimension :: Dimension()
{
    length = 0.0f;
    breadth = 0.0f;
    depth = 0.0f;
}

//Function to get details related to Dimension of a particular gadget
void Dimension :: input(string fname)
{
    stringstream ss;
    ofstream file;

    cout << endl << "                                                        DIMENSION" << endl << endl;

    cout << "               ENTER LENGTH (cm)  : ";
    cin >> length;

    cout << "               ENTER BREADTH (cm) : ";
    cin >> breadth;

    cout << "               ENTER DEPTH (cm)   : ";
    cin >> depth;

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "LENGTH  : " << length << " cm" << endl;
    file << "BREADTH : " << breadth << " cm" << endl;
    file << "DEPTH   : " << depth << " cm" << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Dimension details from a particular gadget
void Dimension :: display(string fname)
{
    cout << endl << "                                                        DIMENSION" << endl << endl;

    Utilities :: print(fname,"LENGTH  :");
}
