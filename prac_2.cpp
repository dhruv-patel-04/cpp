#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;

struct employee
{
    int id;
    string name;
    string qualification;
    float exp;
    long long c_no;
};

int main()
{
    struct employee e[1000];
    int choice, serial;

    while(1)
    {
        cout<< "Enter 1 to add Employee Details.\n";
        cout<< "Enter 2 to view Employee Details.\n";
        cout<< "Enter 3 to EXIT.\n";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        case 1 :
            cout<<"\nEnter employee ID : ";
            cin>>serial;
            fflush(stdin);
            e[serial].id = serial;

            cout<<"Enter Name of Employee : ";
            cin >> e[serial].name;
            fflush(stdin);

            cout<<"Enter Qualification of Employee : ";
            cin >> e[serial].qualification;
            fflush(stdin);

            cout<<"Enter Experience of Employee in years : ";
            cin >> e[serial].exp;
            fflush(stdin);

            cout<<"Enter the contact number of Employee : ";
            cin >> e[serial].c_no;
            fflush(stdin);
            cout<<endl;
            break;

        case 2 :
            system("cls");
            cout<<"Enter employee ID : ";
            cin>>serial;
            fflush(stdin);
            cout << endl;

            if(e[serial].id == serial)
            {
                cout << "--------------------------------" << endl;
                cout << "\nEmployee Name : " << e[serial].name << endl;
                cout << "\nQualification : " << e[serial].qualification << endl;
                cout << "\nExperience : " << e[serial].exp << endl;
                cout << "\nContact Number : " << e[serial].c_no << endl << endl;
                cout << "--------------------------------" << endl << endl;
            }
            else
            {
                cout << "********************************" << endl;
                cout << "\nERROR : ENTERED EMPLOYEE ID DOES NOT EXIST.\n" << endl;
                cout << "********************************" << endl << endl;
            }
            break;

        case 3 :
            exit(0);
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }
}
