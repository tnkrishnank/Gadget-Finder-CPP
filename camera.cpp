//Header Files
#include "camera.h"
#include "utilities.h"

#include <fstream>
#include <sstream>

//Constructor
Camera :: Camera()
{
    nCamera = 0;
    specs = "";
}

//Function to get details related to Camera of a particular gadget
void Camera :: input(string fname)
{
    stringstream ss;
    ofstream file;

    cout << endl << "                                                         CAMERA" << endl << endl;

    cout << "               ENTER NUMBER OF CAMERAS    : ";
    cin >> nCamera;

    fflush(stdin);

    cout << "               ENTER CAMERA SPECIFICATION : ";
    getline(cin,specs);
    specs = Utilities :: toUpper(specs);

    ss << fname;
    file.open(ss.str(),ios::app);

    file << "NUMBER OF CAMERAS : " << nCamera << endl;
    file << "SPECIFICATIONS    : " << specs << endl;
    file << endl;

    file.close();
}

//Function to fetch and display Camera details from a particular gadget
void Camera :: display(string fname)
{
    cout << endl << "                                                         CAMERA" << endl << endl;

    Utilities :: print(fname,"NUMBER OF CAMERAS :");
}
