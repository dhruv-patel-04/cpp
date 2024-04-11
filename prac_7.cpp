#include<iostream>

using namespace std;

//class of calc to store data, calculate and display output
class calc
{
    int real;
    int img;

    //below are public object which can be accessed within main() also
public :

    //default constructor is created
    calc()
    {
        real=0;
        img=0;
    }

    //function to collect data from user
    void getdata()
    {
        cout<<"Enter Real Part : ";
        cin >> real;
        fflush(stdin);

        cout<<"Enter Imaginary Part : ";
        cin >> img;
        fflush(stdin);
    }


    //function to display the output
    void putdata()
    {
        if(img<0)
        {
            cout <<real <<img <<"i";
        }
        else
        {
            cout <<real << "+" <<img <<"i";
        }
    }

    //below binary operator is overloaded

    //+ operator is overloaded
    calc operator+ (calc &n)
    {
        calc temp;
        temp.real = real + n.real;
        temp.img = img + n.img;
        return temp;
    }

    //- operator is overloaded
    calc operator- (calc &n)
    {
        calc temp;
        temp.real = real - n.real;
        temp.img = img - n.img;
        return temp;
    }

    //* operator is overloaded
    calc operator* (calc &n)
    {
        calc temp;
        temp.real = (real * n.real) - (img * n.img);
        temp.img = (real * n.img) + (img * n.real);
        return temp;
    }

    //'/' operator is overloaded
    calc operator/ (calc &n)
    {
        calc temp;
        int denominator;
        denominator = (img * img) + (n.img * n.img);
        temp.real = ((real * n.real) + (img * n.img)) / denominator;
        temp.img = ((img * n.real) - (real * n.img)) / denominator;
        return temp;
    }

    //here unary operator is overloaded
    calc operator! ()
    {
        calc temp;
        temp.real = real * (-1);
        temp.img = img * (-1);
        return temp;
    }
};

int main()
{
    //object of class calc are created
    calc num1,num2,result;
    char choice;

    //function call for collecting data
    num1.getdata();
    num2.getdata();

    while(1)
    {
        //menu selection
        cout<< "\nChoose operation\n";
        cout<< "(+) addition\n";
        cout<< "(-) subtraction\n";
        cout<< "(*) multiplication\n";
        cout<< "(/) division\n";
        cout<< "(!) negation\n";
        cout<< "0 to EXIT\n";

        //choice is collected from user.
        cout<<"Enter your choice : ";
        cin>>choice;
        fflush(stdin);

        switch(choice)
        {
        case '+' :
        {
            result = num1 + num2;
            result.putdata();
            break;
        }

        case '-' :
        {
            result = num1 - num2;
            result.putdata();
            break;
        }

        case '*' :
        {
            result = num1 * num2;
            result.putdata();
            break;
        }

        case '/' :
        {
            result = num1 / num2;
            result.putdata();
            break;
        }

        case '!' :
        {
            result = !num1;
            result.putdata();
            cout<<endl;
            result = !num2;
            result.putdata();
            break;
        }

        case '0':
            exit(0);
            break;

        //default case for invalid choice
        default :
            cout<<"Enter valid option.\n";
            break;
        }
    }
}
