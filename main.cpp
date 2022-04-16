//Header Files
#include "airconditioner.h"
#include "hometheatre.h"
#include "laptop.h"
#include "mobile.h"
#include "powerbank.h"
#include "smartwatch.h"
#include "television.h"

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>

using namespace std;

//Function declaration
void homepage();

//Function to list all models of a particular gadget
string listData(string device, string label)
{
    system("cls");

    stringstream ss;
    ifstream file;
    ifstream file1;

    ss << device;
    file.open(ss.str());

    int i = 1;
    int j;
    int ch = 0;
    string line;
    string line1;

    cout << endl << endl;
    cout << "    ****************************************************************************************************************\n";
    cout << "    * S.NO *          BRAND          *          MODEL          *          PRICE          *       RELEASE YEAR      *\n";
    cout << "    ****************************************************************************************************************\n";

    //Loop to read lines from files of all models of a particular gadget and getting details required
    while(getline(file,line))
    {
        ss.str("");
        ss << label << line << ".txt";
        file1.open(ss.str());

        cout << endl;
        cout << "      " << setw(4) << i;
        i++;

        j = 1;
        while(getline(file1,line1))
        {
            line1 = line1.substr(line1.find(':')+2);
            cout << "  " << setw(23) << line1;
            j++;

            if(j > 4)
                break;
        }

        cout << endl;

        file1.close();
    }

    file.close();

    //Getting user choice to display a particular model
    if(i != 1)
    {
        cout << endl << endl;
        cout << "                                                ";
        cout << "ENTER YOUR CHOICE : ";
        cin >> ch;

        if(ch > i-1)
        {
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *          INVALID CHOICE !!!          *\n";
            cout << "                                        ****************************************\n\n";
            return "";
        }
    }
    else
    {
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *        DEVICES UNAVAILABLE !!!       *\n";
            cout << "                                        ****************************************\n\n";
            return "";
    }

    ss.str("");
    ss << device;
    file.open(ss.str());

    i = 1;
    while(getline(file,line))
    {
        if(i >= ch)
            break;

        i++;
    }

    file.close();

    return line;
}

//Function accessible only by admin to add new model
void addDevice()
{
    system("cls");

    int choice;

home:

    fflush(stdin);

    cout << "\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *              ADD GADGET              *\n";
    cout << "                                        ****************************************\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    1. AIR CONDITIONER                |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    2. HOME THEATRE                   |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    3. LAPTOP                         |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    4. MOBILE                         |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    5. POWER BANK                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    6. SMART WATCH                    |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    7. TELEVISION                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    8. GO BACK                        |\n";
    cout << "                                        |______________________________________|\n\n\n";

    cout << "                                        ENTER YOUR CHOICE : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            AirConditioner obj;
            obj.input();
            break;
        }
        case 2:
        {
            HomeTheatre obj;
            obj.input();
            break;
        }
        case 3:
        {
            Laptop obj;
            obj.input();
            break;
        }
        case 4:
        {
            Mobile obj;
            obj.input();
            break;
        }
        case 5:
        {
            PowerBank obj;
            obj.input();
            break;
        }
        case 6:
        {
            SmartWatch obj;
            obj.input();
            break;
        }
        case 7:
        {
            Television obj;
            obj.input();
            break;
        }
        case 8:
            homepage();
            break;
        default:
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *          INVALID CHOICE !!!          *\n";
            cout << "                                        ****************************************\n\n";
            cout << "                                            ";
            system("pause");
            system("cls");
            goto home;
    }

    cout << "\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *       DEVICE ADDED SUCCESSFULLY      *\n";
    cout << "                                        ****************************************\n\n";
    cout << "                                            ";
    system("pause");
    addDevice();
}

//Function to view details of a particular model
void viewDevice()
{
    system("cls");

    int choice;
    string ch = "";

home:

    fflush(stdin);

    cout << "\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *             GADGET FINDER            *\n";
    cout << "                                        ****************************************\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    1. AIR CONDITIONER                |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    2. HOME THEATRE                   |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    3. LAPTOP                         |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    4. MOBILE                         |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    5. POWER BANK                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    6. SMART WATCH                    |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    7. TELEVISION                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    8. GO BACK                        |\n";
    cout << "                                        |______________________________________|\n\n\n";

    cout << "                                        ENTER YOUR CHOICE : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            ch = listData("GAD AIR CONDITIONER.txt","A ");
            if(ch != "")
                AirConditioner :: display(ch);
            break;
        case 2:
            ch = listData("GAD HOME THEATRE.txt","H ");
            if(ch != "")
                HomeTheatre :: display(ch);
            break;
        case 3:
            ch = listData("GAD LAPTOP.txt","L ");
            if(ch != "")
                Laptop :: display(ch);
            break;
        case 4:
            ch = listData("GAD MOBILE.txt","M ");
            if(ch != "")
                Mobile :: display(ch);
            break;
        case 5:
            ch = listData("GAD POWER BANK.txt","P ");
            if(ch != "")
                PowerBank :: display(ch);
            break;
        case 6:
            ch = listData("GAD SMART WATCH.txt","S ");
            if(ch != "")
                AirConditioner :: display(ch);
            break;
        case 7:
            ch = listData("GAD TELEVISION.txt","T ");
            if(ch != "")
                Television :: display(ch);
            break;
        case 8:
            homepage();
            break;
        default:
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *          INVALID CHOICE !!!          *\n";
            cout << "                                        ****************************************\n\n";
            cout << "                                            ";
            system("pause");
            system("cls");
            goto home;
    }

    cout << "\n\n";
    cout << "                                            ";
    system("pause");
    viewDevice();
}

//Function to display and choose between options available for admin
void adminOpt()
{
    system("cls");

    int choice;

home:

    fflush(stdin);

    cout << "\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *                 ADMIN                *\n";
    cout << "                                        ****************************************\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    1. ADD DEVICE                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    2. VIEW DEVICE                    |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    3. GO BACK                        |\n";
    cout << "                                        |______________________________________|\n\n\n";

    cout << "                                        ENTER YOUR CHOICE : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addDevice();
            break;
        case 2:
            viewDevice();
            break;
        case 3:
            homepage();
            break;
        default:
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *          INVALID CHOICE !!!          *\n";
            cout << "                                        ****************************************\n\n";
            cout << "                                            ";
            system("pause");
            system("cls");
            goto home;
    }

    cout << "\n\n";
    cout << "                                            ";
    system("pause");
    adminOpt();
}

//Function to enter admin page only if the password matches
void admin()
{
    int i;
    char a = 'a';
    char password[25];

    cout << "\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *             ADMIN ACCESS             *\n";
    cout << "                                        ****************************************\n\n";
    cout << "                                        PASSWORD : ";

    //Loop to get password letter by letter and hiding it
    i = 0;
    while(a != '\r')
    {
        a = getch();
        if(a == '\r' && i == 0)
        {
            cout << "\n\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *           INVALID PASSWOORD          *\n";
            cout << "                                        ****************************************\n\n";
            cout << "                                            ";
            system("pause");
            homepage();
        }
        if(a == '\b' && i > 0)
        {
            i--;
            putch(a);
            putch(' ');
            putch(a);
        }
        else if(a != '\r' && a != '\b')
        {
            putch('*');
            password[i] = a;
            i++;
        }
    }
    password[i] = '\0';

    //Comparing the entered password
    if(strcmp(password,"12345") == 0)
    {
        adminOpt();
    }
    else
    {
        cout << "\n\n";
        cout << "                                        ****************************************\n";
        cout << "                                        *           INVALID PASSWOORD          *\n";
        cout << "                                        ****************************************\n\n";
        cout << "                                            ";
        system("pause");
        homepage();
    }
}

//Function to choose between admin and customer
void homepage()
{
    system("cls");
    system("COLOR 70");

    int choice;

home:

    fflush(stdin);

    cout << "\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *                ACCESS                *\n";
    cout << "                                        ****************************************\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    1. ADMIN                          |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    2. CUSTOMER                       |\n";
    cout << "                                        |______________________________________|\n\n\n";

    cout << "                                        ENTER YOUR CHOICE : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            admin();
            break;
        case 2:
            viewDevice();
            break;
        default:
            cout << "\n";
            cout << "                                        ****************************************\n";
            cout << "                                        *          INVALID CHOICE !!!          *\n";
            cout << "                                        ****************************************\n\n";
            cout << "                                            ";
            system("pause");
            system("cls");
            goto home;
    }

    cout << "                                            ";
    system("pause");
    homepage();
}

//Main function where the program execution starts
int main()
{
    int i;

    char a = 219;

    system("COLOR 02");

    cout << "\n\n\n\n\n\n";
    cout << "                                        ****************************************\n";
    cout << "                                        *             GADGET FINDER            *\n";
    cout << "                                        ****************************************\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    DESIGNED BY :                     |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    20PC13 - GURU PRASANNA V          |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    20PC22 - NAVIN KRISHNA T          |\n";
    cout << "                                        |                                      |\n";
    cout << "                                        |    20PC37 - VETRIVEL M D             |\n";
    cout << "                                        |______________________________________|\n\n";
    cout << "                                                       LOADING...\n\n";
    cout << "                                        ";

    for (i = 1; i <= 40; i++)
    {
        cout << a;
        Sleep(50);
    }

    homepage();

    return 0;
}
