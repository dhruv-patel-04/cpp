//Do changes in practical 2
//count avg experience of employee
//display avg experience

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;

//structure of employee to store data
class employee
{
    string name;
    string qualification;
    float exp;
    long long c_no;
    static float total_exp;         //static variable is created one only. i.e. it is common for all object of class

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
        total_exp = total_exp + exp;
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

    //function to display average experience of employee
    //static function defination
    static void dis_avg(int serial)
    {
        cout<<"The average experience of all the employee is "<<total_exp/serial<<endl<<endl;
    }
};

//initialization of static variable
//NOTE : static variable must be declared outside of class, declaration like : static float avg_exp =0; is invalid.
//Also, static float avg_exp;
        //avg_exp =0;           this is also invalid.

float employee :: total_exp = 0;

int main()
{
    class employee e[1000];
    int choice, serial=0, temp=0;               //serial will be used for array index in loop


    while(1)
    {
        //menu selection
        cout<< "Enter 1 to add Employee Details.\n";
        cout<< "Enter 2 to view Employee Details.\n";
        cout<< "Enter 3 to view Average Experience Of Employee.\n";
        cout<< "Enter 4 to EXIT.\n";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        //case to add employee details
        case 1 :
            {
            cout<<"\nEnter employee ID : ";
            cin >> e[serial].id;
            e[serial].getdata();        //getdata function is called
            serial++;
            break;
            }

        //case to view employee details
        case 2 :
            {
            int check=0;
            system("cls");                          //to clear screen
            cout<<"Enter employee ID : ";
            cin>>temp;
            fflush(stdin);
            cout << endl;
            for(int i =0; i<serial; i++)
            {
                if(e[i].id == temp)
                {
                e[i].putdata();                     //putdata function is called
                check++;
                }
            }
            if(check==0)
            {
                cout << "********************************" << endl;
                cout << "\nERROR : ENTERED EMPLOYEE ID DOES NOT EXIST.\n" << endl;
                cout << "********************************" << endl << endl;
            }
            break;}


        case 3 :
            system("cls");
            employee :: dis_avg(serial);                    //calling of static functiion, NOTE : only dis_avg(serial); is invalid for static.
            break;

        case 4 :
            exit(0);            //function to exit program
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }
}
