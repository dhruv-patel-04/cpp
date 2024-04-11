#include<iostream>
#include<string.h>

using namespace std;

//grand parent class
class literature
{
    int id;
    string title;

public :

    //function to collect data from user
    void getdata()
    {
        cout<<"ID : ";
        cin>>id;
        fflush(stdin);

        cout<<"Title : ";
        fflush(stdin);
        getline(cin,title);
    }

    //function to display data
    void putdata()
    {
        cout<<id<<" ";
        cout<<title<<"\t";
    }
};


//To avoid duplication, grandparent class need to inherited virtually in parent class.
class e_lit : virtual protected literature
{
    string doi;

public :
    void getdata()
    {
        cout<<"DOI : ";
        cin>>doi;
        fflush(stdin);
    }

    void putdata()
    {
        cout<<doi;
    }
};

//To avoid duplication, grandparent class need to inherited virtually in parent class.
class hardb_lit : virtual protected literature
{
    int no_of_copy;

public :
    void getdata()
    {
        cout<<"In stock copies : ";
        cin>>no_of_copy;
        fflush(stdin);
    }

    void putdata()
    {
        cout<<no_of_copy<<"copies";
    }
};

//child class
class book : protected e_lit, protected hardb_lit           //multiple inheritannce
{
    int ISBN;
    char c;

public :
    void getdata()
    {
        literature :: getdata();
        cout<<"ISBN : ";
        cin>>ISBN;
        fflush(stdin);
        cout<<"(E)copy or (H)ardbound : ";
        cin>>c;
        fflush(stdin);
        if(c=='E')
        {
            e_lit :: getdata();
        }
        else if(c=='H')
        {
            hardb_lit :: getdata();
        }
    }

    void putdata()
    {
        literature :: putdata();
        cout<<"\t"<<ISBN<<"\t";
        if(c=='E')
        {
            e_lit :: putdata();
        }
        else if(c=='H')
        {
            hardb_lit :: putdata();
        }
        cout<<endl;
    }
};

//child class
class magazine : protected e_lit, protected hardb_lit       //multiple inheritannce
{
    int ISSN;
    char c;
public :
    void getdata()
    {
        literature :: getdata();
        cout<<"ISSN : ";
        cin>>ISSN;
        fflush(stdin);
        cout<<"(E)copy or (H)ardbound : ";
        cin>>c;
        fflush(stdin);
        if(c=='E')
        {
            e_lit :: getdata();
        }
        else if(c=='H')
        {
            hardb_lit :: getdata();
        }
    }

    void putdata()
    {
        literature :: putdata();
        cout<<"\t"<<ISSN<<"\t";
        if(c=='E')
        {
            e_lit :: putdata();
        }
        else if(c=='H')
        {
            hardb_lit :: putdata();
        }
        cout<<endl;
    }
};


int main()
{
    int choice=0;
    book b[10];
    magazine m[10];
    char ch;
    int i=0, b_serial=0, m_serial=0;

    //menu selection
    while(1)
    {
        cout<< "Enter 1 : Add book data."<<endl;
        cout<< "Enter 2 : Add magazine data."<<endl;
        cout<< "Enter 3 : List all books."<<endl;
        cout<< "Enter 4 : List all magazines."<<endl;
        cout<< "Enter your choice : ";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
            //case to add book data
        case 1 :
        {
            cout<<"***** Add book data *****"<<endl;
            b[b_serial].getdata();
            b_serial++;
            cout<<"------------------------------------\n";
            cout<<"Enter M to goto Main Menu. Press any key to exit : ";
            cin>>ch;
            if(ch == 'M')
            {
                continue;
            }
            else
            {
                exit(0);
            }
            break;
        }

            //case to add magazine data
        case 2 :
        {
            cout<<"***** Add magazine data *****"<<endl;
            m[m_serial].getdata();
            m_serial++;
            cout<<"------------------------------------\n";
            cout<<"Enter M to goto Main Menu. Press any key to exit : ";
            cin>>ch;
            if(ch == 'M')
            {
                continue;
            }
            else
            {
                exit(0);
            }

            break;
        }


            //case to display all books data
        case 3 :
        {
            cout<<"***** List all books *****"<<endl;
            for(int i=0; i<b_serial; i++)
            {
                b[i].putdata();
            }
            cout<<"------------------------------------\n";
            cout<<"Enter M to goto Main Menu. Press any key to exit : ";
            cin>>ch;
            if(ch == 'M')
            {
                continue;
            }
            else
            {
                exit(0);
            }
            break;
        }

            //case to display all magazine data
        case 4 :
        {
            cout<<"***** List all magazine *****"<<endl;
            for(int i=0; i<m_serial; i++)
            {
                m[i].putdata();
            }
            cout<<"------------------------------------\n";
            cout<<"Enter M to goto Main Menu. Press any key to exit : ";
            cin>>ch;
            if(ch == 'M')
            {
                continue;
            }
            else
            {
                exit(0);
            }
            break;
        }

        default :
            exit(0);
            break;
        }
    }
    return 0;
}
