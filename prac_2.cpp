#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;


//structure of employee to store data
struct employee
{
    //below are private object accessed within structure only
private :
    string name;
    string qualification;
    float exp;
    long long c_no;

    //below are public object which can be accessed within main() also
public :
    int id;

    //function to collect data from user
    void getdata()
    {
        cout<<"Enter Name of Employee : ";
        cin >> name;
        fflush(stdin);

        cout<<"Enter Qualification of Employee : ";
        cin >> qualification;
        fflush(stdin);

        cout<<"Enter Experience of Employee in years : ";
        cin >> exp;
        fflush(stdin);

        cout<<"Enter the contact number of Employee : ";
        cin >> c_no;
        fflush(stdin);
        cout<<endl;
    }


    //function to display the stored data
    void putdata()
    {
        cout << "--------------------------------" << endl;
        cout << "\nEmployee Name : " << name << endl;
        cout << "\nQualification : " << qualification << endl;
        cout << "\nExperience : " << exp << endl;
        cout << "\nContact Number : " << c_no << endl << endl;
        cout << "--------------------------------" << endl << endl;
    }
};

int main()
{
    struct employee e[1000];
    int choice, serial;

    while(1)
    {
        //menu selection
        cout<< "Enter 1 to add Employee Details.\n";
        cout<< "Enter 2 to view Employee Details.\n";
        cout<< "Enter 3 to EXIT.\n";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        //case to add employee details
        case 1 :
            cout<<"\nEnter employee ID : ";
            cin>>serial;
            fflush(stdin);
            e[serial].id = serial;
            e[serial].getdata();                    //getdata function is called
            break;

        //case to view employee details
        case 2 :
            system("cls");                          //to clear screen
            cout<<"Enter employee ID : ";
            cin>>serial;
            fflush(stdin);
            cout << endl;
            if(e[serial].id == serial)
            {
                e[serial].putdata();                 //putdata function is called
            }
            else
            {
                cout << "********************************" << endl;
                cout << "\nERROR : ENTERED EMPLOYEE ID DOES NOT EXIST.\n" << endl;
                cout << "********************************" << endl << endl;
            }
            break;


        case 3 :
            exit(0);            //function to exit program
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }
}
