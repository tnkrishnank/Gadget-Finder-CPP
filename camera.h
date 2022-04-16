#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

using namespace std;

//Class containing data related to Camera
class Camera
{
    public:
        //Constructor
        Camera();

        //Data Members
        int nCamera;
        string specs;

        //Member Functions
        void input(string fname);
        static void display(string fname);

    protected:

    private:
};

#endif // CAMERA_H
