#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;

//employee is parent class
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
    void getempdata()
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

    //function to display employee data
    void putempdata()
    {
        cout << "\nEmployee Name : " << name << endl;
        cout << "\nQualification : " << qualification << endl;
        cout << "\nExperience : " << exp << endl;
        cout << "\nContact Number : " << c_no << endl;
    }

    //function is used to keep id as private
    int getid()
    {
        return id;
    }

public :
    //function to display avg experience
    static void dis_avg(int serial)
    {
        cout<<"The average experience of all the employee is "<<total_exp/serial<<endl<<endl;
    }
};

float employee :: total_exp = 0;        //static variable initialization


//teachingemployee is a child class of employee
class teachingemployee : private employee
{
    string designation, specialization, payscale;

public :

    //function to get teaching employee data
    void gettempdata()
    {
    getempdata();
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

    //function to display teaching employee data
    void puttempdata()
    {
    cout << "--------------------------------" << endl;
    putempdata();
    cout << "\nDesignation : " << designation << endl;
    cout << "\nSpecialization : " << specialization <<endl;
    cout << "\nPay Scale: " << payscale << endl << endl;
    cout << "--------------------------------" << endl << endl;
    }

    //function to search if ID is available or not
    int searchtemp(int temp)
    {
        if(getid() == temp)
        {
        puttempdata();
        return 1;
        }
    }
};


//nonteachingemployee is child class of employee. Here Hierarchical Inheritance is used
class nonteachingemployee : private employee
{
    int salary;

public :

    //function to get non teaching employee data
    void getntempdata()
    {
    getempdata();
    cout<<"Enter Salary of Employee : ";
    cin >> salary;
    fflush(stdin);
    cout<<endl;
    }

    //function to display non teaching employee data
    void putntempdata()
    {
    cout << "--------------------------------" << endl;
    putempdata();
    cout << "\nSalary : " << salary << endl << endl;
    cout << "--------------------------------" << endl << endl;
    }

    //function to search if ID is available or not
    int searchntemp(int temp)
    {
        if(getid() == temp)
        {
        putntempdata();
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
            tempy[t_serial].gettempdata();
            t_serial++;
            break;
            }

        //case to add non teaching employee details
        case 2 :
            {
            ntempy[nt_serial].getntempdata();
            nt_serial++;
            break;
            }

        //case to view employee details by id
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
            check = tempy[i].searchtemp(temp);
            }
            if(check!=1)
            {
                for(int i =0; i<nt_serial; i++)
                {
                check = ntempy[i].searchntemp(temp);
                }
            }
            if(check!=1)
                {
                cout << "********************************" << endl;
                cout << "\nERROR : ENTERED EMPLOYEE ID DOES NOT EXIST.\n" << endl;
                cout << "********************************" << endl << endl;
                }
            break;}


        //case to display avg experience of employee
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
