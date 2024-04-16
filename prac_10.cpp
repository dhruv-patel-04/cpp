//Basic to class conversion
#include<iostream>

using namespace std;

class employee
{
    int year;
    int month;

public :
    //default constructor
    employee()
    {
        year =0;
        month =0;
    }

    //parameterized constructor
    employee(float &e)
    {
        year = e;
        month = 12*(e-year);
    }

    //display output
    void display()
    {
        cout<<"Employee experience is "<<year<<" years and "<<month<<" months";
    }
};

int main()
{
    float exp;
    cout<<"Enter employee experience : ";
    cin>>exp;

    employee e;         //object is created and default constructor is called
    e = exp;            //basic data type is assigned to class object
    e.display();
    return 0;
}
