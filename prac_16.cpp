#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<fstream>

using namespace std;


//class named tata to store data
class tata
{
    //below are private object accessed within class only
    string model;
    string type;
    string price;
    string mileage;
    string transmission;
    string tank_capacity;
    string seating;
    string airbag;

    //below are public object which can be accessed within main() also
public :
    //function to asign data from file
    void getdata(string m, string typ, string p, string mil, string trans, string tnk, string s, string a)
    {
        model = m;
        type = typ;
        price = p;
        mileage = mil;
        transmission = trans;
        tank_capacity = tnk;
        seating = s;
        airbag = a;
    }


    //function to display the stored data
    void putdata()
    {
        cout<<"Enter Model Name : ";
        cin >> model;
        fflush(stdin);

        cout<<"Enter Fuel Type : ";
        cin >> type;
        fflush(stdin);

        cout<<"Enter Showroom price : ";
        cin >> price;
        fflush(stdin);

        cout<<"Enter Mileage : ";
        cin >> mileage;
        fflush(stdin);


        cout<<"Enter Transmission Type : ";
        cin >> transmission;
        fflush(stdin);

        cout<<"Enter Fuel Tank Capacity : ";
        cin >> tank_capacity;
        fflush(stdin);

        cout<<"Enter Seating Capacity : ";
        cin >> seating;
        fflush(stdin);

        cout<<"Does it have Airbags (yes/no) : ";
        cin >> airbag;
        fflush(stdin);
        cout<<endl;
    }


    //function to display names of cars
    void  by_name()
    {
        cout<<model<<"\t";
    }


    //function to display by names
    void display_by_name()
    {
        cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
    }


    //function to display by fuel type
    void display_by_fuel(int selection)
    {
        //below is menu selection based on entered fuel type
        switch(selection)
        {
        case 1 :
            if(type=="petrol" || type=="PETROL" || type=="Petrol")
            {
                cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
            }
            break;

        case 2 :
            if(type=="diesel" || type=="DIESEL" || type=="Diesel")
            {
                cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
            }
            break;

        case 3 :
            if(type=="CNG" || type=="cng" || type=="Cng")
            {
                cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
            }
            break;

        case 4 :
            if(type=="electric" || type=="ELECTRIC" || type=="Electric")
            {
                cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
            }
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }


    //function to display by price range
    void display_by_price(float selection)
    {
        float temp = stof(price);       //here price is declared as string because we get data from file
                                        //stof() is function used to convert string to float
        if(temp<=selection)
        {
            cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
        }
    }
};

int main()
{
    int i,n=0;
    string str;             //used to hold string (data) of one car

    ifstream f;
    f.open("cardata.txt",ios :: in);        //file is open in reading mode

    while(getline(f, str, ';'))
    {
        n++;                //n will give total no. of cars
    }

    f.close();

    class tata car[n];
    string model;
    string type;
    string price;
    string mileage;
    string transmission;
    string tank_capacity;
    string seating;
    string airbag;

    int p[7];           //holds index of commas

    f.open("cardata.txt",ios :: in);
    //loop for entering car details
    for(i=0; i<n; i++)
    {
        getline(f, str, ';');

        for(int i=0; i<7; i++)
        {
            p[i] = str.find(",", p[i-1]+1);         //string index of commas in array
        }

        //slicing of string str having detail of one car using substr();
        model = str.substr(0, p[0]);
        type = str.substr(p[0]+1 , p[1]-p[0]-1);
        price = str.substr(p[1]+1, p[2]-p[1]-1);
        mileage = str.substr(p[2]+1, p[3]-p[2]-1);
        transmission = str.substr(p[3]+1, p[4]-p[3]-1);
        tank_capacity = str.substr(p[4]+1, p[5]-p[4]-1);
        seating = str.substr(p[5]+1, p[6]-p[5]-1);
        airbag = str.substr(p[6]+1);

        car[i].getdata(model, type, price, mileage, transmission, tank_capacity, seating, airbag);
    }

    cout<<"File read successfully"<<endl;
    f.close();              //closing of file

    int choice;

    while(1)
    {
        //menu selection
        cout<< "Enter 1 to view car details OR 0 to EXIT.\n";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        case 1 :            //case to view details
            system("cls");
            cout<< "WELCOME TO TATA MOTORS" << endl;
            cout<< "\nGET THE CAR DETAILS AS PER YOUR PREFERENCE\n" << endl;
            cout<< "(1) Model Name  (2) Fuel Type  (3) Price Range\n";

            int detail_choice;
            int selection;

            cout<<"\nENTER YOUR OPTION : ";
            cin>>detail_choice;
            fflush(stdin);
            cout<<"\n----------------------\n";

            //below is nested switch case to print details based on preference
            switch(detail_choice)
            {
            case 1 :                                //case to display by name
                cout<<"\nLIST OF TATA CARS\n\n";
                for(i=0; i<n; i++)
                {
                    cout<<"("<<i+1<<") ";
                    car[i].by_name();
                }

                cout<<"\n\n\nCHOOSE YOUR CAR TO GET DETAILS : ";
                cin>>selection;
                fflush(stdin);
                cout<<endl;

                cout<<setw(6)<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(10)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(10)<<"Seating"<<setw(10)<<"Airbags";
                cout<<endl<<setw(28)<<"(Lakhs)"<<" (Km/L)"<<setw(26)<<"(Liters)"<<setw(16)<<"Capacity"<<endl;
                car[selection-1].display_by_name();
                break;

            case 2 :                                //case to display by fuel type
                cout<<"\nTATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS\n\n";
                cout<<"(1)Petrol  (2)Diesel  (3)CNG  (4)Electric";

                cout<<"\n\nENTER YOUR FUEL PREFERENCE : ";
                cin>>selection;
                fflush(stdin);
                cout<<endl;

                cout<<setw(6)<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(10)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(10)<<"Seating"<<setw(10)<<"Airbags";
                cout<<endl<<setw(28)<<"(Lakhs)"<<" (Km/L)"<<setw(26)<<"(Liters)"<<setw(16)<<"Capacity"<<endl;
                for(i=0; i<n; i++)
                {
                    car[i].display_by_fuel(selection);
                }
                break;

            case 3 :                                    //case to display by budget
                float temp;
                cout<<"\nENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
                cin>>temp;
                fflush(stdin);
                cout<<endl;

                cout<<setw(6)<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(10)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(10)<<"Seating"<<setw(10)<<"Airbags";
                cout<<endl<<setw(28)<<"(Lakhs)"<<" (Km/L)"<<setw(26)<<"(Liters)"<<setw(16)<<"Capacity"<<endl;
                for(i=0; i<n; i++)
                {
                    car[i].display_by_price(temp);
                }
                break;

            default :
                cout<<"Enter valid option.\n";
                break;
            }
            break;


        case 0 :           //case to exit loop
            exit(0);
            break;

        default :
            cout<<"Enter valid option.\n";
            break;
        }
        cout<<endl;
    }
}
