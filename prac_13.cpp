//same as practical 8 but here function names are same
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;

class employee
{
private :
    int id;
    string name;
    string qualification;
    float exp;
    long long c_no;
    static float total_exp;

protected :

    //input of employee data
    void getdata()
    {
        cout<<"\nEnter employee ID : ";
        cin >> id;

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
    }

    //output of employee data
    void putdata()
    {
        cout << "\nEmployee Name : " << name << endl;
        cout << "\nQualification : " << qualification << endl;
        cout << "\nExperience : " << exp << endl;
        cout << "\nContact Number : " << c_no << endl;
    }

    //used to keep id private
    int getid()
    {
        return id;
    }

public :

    //display avg experience
    static void dis_avg(int serial)
    {
        cout<<"The average experience of all the employee is "<<total_exp/serial<<endl<<endl;
    }
};

float employee :: total_exp = 0;

//child class of employee
class teachingemployee : private employee
{
    string designation, specialization, payscale;

public :

    //function name is same as in parent class
    void getdata()
    {
    employee :: getdata();      //scope resolution is used because by default getdata() of child class is called
    cout<<"Enter Designation of Employee : ";
    cin >> designation;
    fflush(stdin);

    cout<<"Enter specialization of Employee : ";
    cin >> specialization;
    fflush(stdin);

    cout<<"Enter pay scale of Employee : ";
    cin >> payscale;
    fflush(stdin);
    cout<<endl;
    }
    void putdata()
    {
    cout << "--------------------------------" << endl;
    employee :: putdata();
    cout << "\nDesignation : " << designation << endl;
    cout << "\nSpecialization : " << specialization <<endl;
    cout << "\nPay Scale: " << payscale << endl << endl;
    cout << "--------------------------------" << endl << endl;
    }

    //check if ID exists or not
    int searchid(int temp)
    {
        if(getid() == temp)
        {
        putdata();
        return 1;
        }
    }
};


//child class of employee
//same as of teaching employee
class nonteachingemployee : private employee
{
    int salary;

public :
    void getdata()
    {
    employee :: getdata();
    cout<<"Enter Salary of Employee : ";
    cin >> salary;
    fflush(stdin);
    cout<<endl;
    }
    void putdata()
    {
    cout << "--------------------------------" << endl;
    employee :: putdata();
    cout << "\nSalary : " << salary << endl << endl;
    cout << "--------------------------------" << endl << endl;
    }
    int searchid(int temp)
    {
        if(getid() == temp)
        {
        putdata();
        return 1;
        }
    }
};

int main()
{
    teachingemployee tempy[500];
    nonteachingemployee ntempy[500];
    int choice, t_serial=0, nt_serial=0, temp=0;


    while(1)
    {
        //menu selection
        cout<< "Enter 1 to add Teaching Employee Details.\n";
        cout<< "Enter 2 to add Non Teaching Employee Details.\n";
        cout<< "Enter 3 to view Employee Details.\n";
        cout<< "Enter 4 to view Average Experience Of Employee.\n";
        cout<< "Enter 5 to EXIT.\n";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        //case to add teaching employee details
        case 1 :
            {
            tempy[t_serial].getdata();
            t_serial++;
            break;
            }

        //case to add non teaching employee details
        case 2 :
            {
            ntempy[nt_serial].getdata();
            nt_serial++;
            break;
            }

        //case to view employee details
        case 3 :
            {
            int check=0;
            system("cls");
            cout<<"Enter employee ID : ";
            cin>>temp;
            fflush(stdin);
            cout << endl;
            for(int i =0; i<t_serial; i++)
            {
            check = tempy[i].searchid(temp);        //returns 1 when id is found and output is obtained
            }
            if(check!=1)
            {
                for(int i =0; i<nt_serial; i++)
                {
                check = ntempy[i].searchid(temp);
                }
            }
            if(check!=1)                    //error mes
                {
                cout << "********************************" << endl;
                cout << "\nERROR : ENTERED EMPLOYEE ID DOES NOT EXIST.\n" << endl;
                cout << "********************************" << endl << endl;
                }
            break;
            }


        //case to display avg experience
        case 4 :
            system("cls");
            employee :: dis_avg(t_serial+nt_serial);
            break;

        case 5 :
            exit(0);
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }
}
