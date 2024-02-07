#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>

using namespace std;


//class named tata to store data
class tata
{
    //below are private object accessed within class only
    string model;
    string type;
    float price;
    float mileage;
    string transmission;
    float tank_capacity;
    int seating;
    string airbag;

    //below are public object which can be accessed within main() also
public :
    //function to collect data from user
    void getdata()
    {
        cout<<"Enter Model Name : ";
        cin >> model;
        fflush(stdin);

        cout<<"Enter Fuel Type (petrol/diesel/cng/electric) : ";
        cin >> type;
        fflush(stdin);

        cout<<"Enter Showroom price (in Lakhs) : ";
        cin >> price;
        fflush(stdin);

        cout<<"Enter Mileage (KM per litre/kg): ";
        cin >> mileage;
        fflush(stdin);


        cout<<"Enter Transmission Type (manual/AMT) : ";
        cin >> transmission;
        fflush(stdin);

        cout<<"Enter Fuel Tank Capacity (litre) : ";
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
    void display_by_price(int selection)
    {
        if(price<=selection)
        {
            cout<<setw(6)<<model<<setw(10)<<type<<setw(10)<<price<<setw(10)<<mileage<<setw(15)<<transmission<<setw(15)<<tank_capacity<<setw(10)<<seating<<setw(10)<<airbag<<endl;
        }
    }
};

int main()
{
    int i,n;
    cout << "Enter Number Of Cars (details to be stored): ";
    cin >> n;

    class tata car[n];

    //loop for entering car details
    for(i=0; i<n; i++)
    {
        cout<<"Enter Details for car " << i+1 << " :\n";
        car[i].getdata();
    }

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

            case 3 :                                //case to display by budget
                cout<<"\nENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
                cin>>selection;
                fflush(stdin);
                cout<<endl;

                cout<<setw(6)<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(10)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(10)<<"Seating"<<setw(10)<<"Airbags";
                cout<<endl<<setw(28)<<"(Lakhs)"<<" (Km/L)"<<setw(26)<<"(Liters)"<<setw(16)<<"Capacity"<<endl;
                for(i=0; i<n; i++)
                {
                    car[i].display_by_price(selection);
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
