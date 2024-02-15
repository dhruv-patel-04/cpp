#include<iostream>

using namespace std;

int active_object;          //here we have declared counter as global variable to keep it defined during whole program

class circle
{
    float radius;           //by default - private
    float area;
public :

    circle()                //default constructor
    {
        radius = 1;
        area = (3.148*radius*radius);
        active_object++;
    }

    circle(float r)         //parameterized constructor
    {
        radius = r;
        area = (3.148*radius*radius);
        active_object++;
    }

    ~circle()               //destructor
    {
        active_object--;
        cout<<"one object deleted"<<endl;
        cout<<"total active objects are "<<active_object<<endl;
    }

    void display()          //display function to print output
    {
        cout<<"circle with radius "<<radius<<" has area "<<area<<endl;
    }
};

int main()
{
    circle *rad;             //rad object is created and default constructor is called
    rad = new circle;        //rad = new circle(); is also valid
    rad -> display();       //if we use pointer then -> is used, . is not valid

    circle *rad1;           //rad1 object is created and parameterized constructor is called with argument 20
    rad1 = new circle(20);
    rad1 -> display();

    delete rad;
    delete rad1;

    circle *rad2;
    rad2 = new circle();
    rad2 -> display();
    delete rad2;

    return 0;
}
