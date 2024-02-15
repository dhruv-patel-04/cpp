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
        area = (3.14*radius*radius);
        active_object++;
    }

    circle(float r)         //parameterized constructor
    {
        radius = r;
        area = (3.14*radius*radius);
        active_object++;
    }

    circle(circle &r)       //copy constructor
    {
        radius = r.radius;
        area = (3.14*r.radius*r.radius);
        active_object++;
    }

    ~circle()               //destructor
    {
        cout<<"one object deleted"<<endl;
        active_object--;
        cout<<"total active objects are "<<active_object<<endl;
    }

    void display()          //display function to print output
    {
        cout<<"circle with radius "<<radius<<" has area "<<area<<endl;
    }
};

int main()
{
    circle rad;             //rad object is created and default constructor is called
    rad.display();

    circle rad1(20);        //rad1 object is created and parameterized constructor is called with argument 20
    rad1.display();

    circle rad2(rad);       //rad2 object is created as copy of rad1 object and here copy constructor is called
    rad2.display();

    return 0;
}
