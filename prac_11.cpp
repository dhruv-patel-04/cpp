//class to basic conversion
#include<iostream>

using namespace std;

class employee
{
    float year;
    float month;
public :

    //logic of conversion
    operator float()
    {
        float temp ;
        temp = year + (((100*month)/12)/100) ;
        return temp;
    }

    //function to collect data from user
    void getdata()
    {
        cout<<"Enter employee experience in years and months\n";
        cout<<"Years : ";
        cin>>year;
        cout<<"Months : ";
        cin>>month;
    }
};

int main()
{
    employee e; //object is created

    e.getdata();  //call of getdata()

    float exp;  //by dafault operator float() is called

    exp = e;    //assignment of object to basic datatype

    cout<<"Employee experience is : "<<exp;
    return 0;
}
