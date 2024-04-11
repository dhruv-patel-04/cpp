//class to class conversion
#include<iostream>

using namespace std;

class centimeter;

class milimeter
{
    float num_mm;
public :

    //default constructor
    milimeter()
    {
        num_mm = 0;
    }

    //parameterized constructor declaration
    milimeter(centimeter &n);

    float getvalue();

    //function to collect data from user
    void getdata()
    {
        cout<<"Enter measurement in mm : ";
        cin>>num_mm;
    }

    //function to display data
    void display()
    {
        cout<<"Measurement in mm : "<<num_mm;
    }
}mm;


class centimeter
{
    float num_cm;
public :

    //default constructor
    centimeter()
    {
        num_cm = 0;
    }


    centimeter(milimeter &n);

    float getvalue();

    //function to collect data from user
    void getdata()
    {
        cout<<"Enter measurement in cm : ";
        cin>>num_cm;
    }

    //function to display data
    void display()
    {
        cout<<"Measurement in cm : "<<num_cm;
    }
}cm;

//constructor defination
milimeter :: milimeter(centimeter &n)
    {
        num_mm = n.getvalue();
    }

//constructor defination
centimeter :: centimeter(milimeter &n)
    {
        num_cm = n.getvalue();
    }

//function defination
float milimeter :: getvalue()
    {
        float temp;
        temp = num_mm /10;
        return temp;
    }

//function defination
float centimeter :: getvalue()
    {
        float temp;
        temp = num_cm * 10;
        return temp;
    }

int main()
{
    while(1)
    {
        //menu selection
        int choice;
        cout<<"Enter 1 : mm to cm converter\n";
        cout<<"Enter 2 : cm to mm converter\n";
        cout<<"Enter 0 to exit.";
        cin>>choice;

        switch(choice)
        {
            //case to convert mm to cm
        case 1 :
            mm.getdata();
            cm = mm;
            cm.display();
            cout<<endl<<endl;
            break;

            //case to convert cm to mm
        case 2 :
            cm.getdata();
            mm = cm;
            mm.display();
            cout<<endl<<endl;
            break;

        case 0 :
            exit(0);
            break;

        default :
            cout<<"Enter valid option.";
            break;
        }
    }
    return 0;
}
