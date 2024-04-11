#include <iostream>

using namespace std;

//function to find area of circle
void area(float a)
{
 cout<<"\nArea of circle is "<<a*a*3.14<<endl;
}

//function to find area of rectangle
void area(float a, float b)
{
 cout<<"\nArea of rectangle is "<<a*b<<endl;
}

//function to find area of cuboid
void area(float a, float b, float c)
{
 cout<<"\nArea of cuboid is "<<2*((a*b)+(b*c)+(a*c));
}

int main()
{
    float a,b,c;
    //input to find area of circle
    cout<<"Enter the radius of a circle : ";
    cin>>a;
    fflush(stdin);
    area(a);

    //input to find area of rectangle
    cout<<"\nEnter the height of a rectangle : ";
    cin>>a;
    fflush(stdin);
    cout<<"\nEnter the width of a rectangle : ";
    cin>>b;
    fflush(stdin);
    area(a,b);

    //input to find area of cuboid
    cout<<"\nEnter the height of a cuboid : ";
    cin>>a;
    fflush(stdin);
    cout<<"\nEnter the width of a cuboid : ";
    cin>>b;
    fflush(stdin);
    cout<<"\nEnter the depth of a cuboid : ";
    cin>>c;
    fflush(stdin);
    area(a,b,c);
}
