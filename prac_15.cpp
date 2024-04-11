#include<iostream>
#include<string.h>

using namespace std;

//parent class
class product
{
protected :
    int product_id;
    string product_name;
    string product_manufacturer;
    float product_price;

public :
    //parameterized constructor in parent class
    product(int p_id, string p_name, string p_manu, float p_price)
    {
    product_id = p_id;
    product_name = p_name;
    product_manufacturer = p_manu;
    product_price = p_price;
    }
    virtual void putdata() = 0 ;
};

//child class
class smartwatch : protected product
{
protected :
    float dial_size;

public :
    //parameterized constructor in child class
    smartwatch(int p_id, string p_name, string p_manu, float p_price, float d_size) : product(p_id, p_name, p_manu, p_price)
    {
    dial_size = d_size;
    }

    void putdata()
    {
    cout<<"-----------------------------------------------\n";
    cout<<product_id<<" : "<<product_name<<" : "<<product_manufacturer<<" : "<<product_price<<" : "<<dial_size<<endl;
    cout<<"-----------------------------------------------\n";
    }
};


//child class
class bedsheet : protected product
{
protected :
    float width;
    float height;

public :

    //parameterized constructor in child class
    bedsheet(int p_id, string p_name, string p_manu, float p_price, float w, float h) : product(p_id, p_name, p_manu, p_price)
    {
    width = w;
    height = h;
    }

    void putdata()
    {
    cout<<"-----------------------------------------------\n";
    cout<<product_id<<" : "<<product_name<<" : "<<product_manufacturer<<" : "<<product_price<<" : "<<width<<" : "<<height<<endl;
    cout<<"-----------------------------------------------\n";
    }
};

int main()
{
    int p_id;
    string p_name, p_manu;
    float p_price, d_size, w, h;

    int choice;
L:
    cout<<"Enter 1 : smart watch menu\n";
    cout<<"Enter 2 : bedsheet menu\n";
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        //case for smartwatch
    case 1 :
        {
            //data is taken as input from user
        cout<<endl;
        cout<<"***** ENTER SMART WATCH DATA *****\n";
        cout<<endl<<"Enter product id : ";
        cin>>p_id;
        fflush(stdin);
        cout<<"Enter product name : ";
        getline(cin,p_name);
        cout<<"Enter product manufacturer : ";
        cin>>p_manu;
        fflush(stdin);
        cout<<"Enter product price : ";
        cin>>p_price;
        fflush(stdin);
        cout<<"Enter product dial size : ";
        cin>>d_size;
        fflush(stdin);

        smartwatch s(p_id, p_name, p_manu, p_price, d_size); //object is created with parameters
        s.putdata();        //display output
        break;
        }

        //case for bedsheet
    case 2 :
        {
            //data is taken from user
        cout<<endl;
        cout<<"***** ENTER BEDSHEET DATA *****\n";
        cout<<endl<<"Enter product id : ";
        cin>>p_id;
        fflush(stdin);
        cout<<"Enter product name : ";
        getline(cin,p_name);
        cout<<"Enter product manufacturer : ";
        cin>>p_manu;
        fflush(stdin);
        cout<<"Enter product price : ";
        cin>>p_price;
        fflush(stdin);
        cout<<"Enter bedsheet width : ";
        cin>>w;
        fflush(stdin);
        cout<<"Enter bedsheet height : ";
        cin>>h;
        fflush(stdin);

        bedsheet b(p_id, p_name, p_manu, p_price, w, h);        //object is created with parameters
        b.putdata();        //display output
        break;
        }

    default :
        cout<<"Invalid choice. Enter valid option\n";
        goto L;         //goto is used to avoid unintentional ending to code
        break;
    }
    return 0;
}
