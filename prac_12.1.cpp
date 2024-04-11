#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class result;

class student
{
    char s_id[8];
    string s_name;
    int sem;

public :
    void getdata_stu()
    {
    //input of student details
    cout<<"Enter Details Of Student"<<endl<<"Student ID : ";
    cin>>s_id;
    fflush(stdin);

    cout<<"Student Name : ";
    cin>>s_name;
    fflush(stdin);

    cout<<"Semester : ";
    cin>>sem;
    fflush(stdin);
    }

    //output of students details
    void putdata_stu()
    {
    cout<<"Student ID : "<<s_id<<endl;
    cout<<"Student Name : "<<s_name<<endl;
    cout<<"Semester : "<<sem<<endl;
    }

    //function is only declared and defined outside the class
    void getdata_result(result &r);
    void putdata_result(result &r);
}s;

class result
{
    string sub[3];
    int credit[3];
    int marks[3][2];
    int grade_point[3][2];
    float sgpa=0;

public :

    //declaration of friend function
    friend void student :: getdata_result(result &r);
    friend void student :: putdata_result(result &r);
}r;


//friend function is defined here
void student :: getdata_result(result &r)
{
    //input of subject names and credit
    for(int i=0;i<3;i++)
    {
     cout<<"Enter Name of subject "<<i+1<<" : ";
     getline(cin,r.sub[i]);
     fflush(stdin);
     cout<<"Enter Credit : ";
     cin>>r.credit[i];
     fflush(stdin);
    }

    //entering marks of student
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<1; j++)
        {
            cout<<"Enter Marks for Subject "<<i+1<<" : "<<endl;
            cout<<"Theory : ";
            cin>>r.marks[i][j];
            fflush(stdin);
            cout<<"Practical : ";
            cin>>r.marks[i][j+1];
            fflush(stdin);
        }
    }
}

//friend function is defined here
void student :: putdata_result(result &r)
{
    //calculate grade_point and display grade
    for(int i=0; i<3; i++)
    {
        cout<<left<<setw(35)<<r.sub[i];
        for(int j=0; j<=1; j++)
        {
            if(r.marks[i][j]>=80)
            {
                cout<<setw(12)<<"AA";
                r.grade_point[i][j]=10;
            }
            else if(r.marks[i][j]>=73)
            {
                cout<<setw(12)<<"AB";
                r.grade_point[i][j]=9;
            }
            else if(r.marks[i][j]>=66)
            {
                cout<<setw(12)<<"BB";
                r.grade_point[i][j]=8;
            }
            else if(r.marks[i][j]>=60)
            {
                cout<<setw(12)<<"BC";
                r.grade_point[i][j]=7;
            }
            else if(r.marks[i][j]>=55)
            {
                cout<<setw(12)<<"CC";
                r.grade_point[i][j]=6;
            }
            else if(r.marks[i][j]>=50)
            {
                cout<<setw(12)<<"CD";
                r.grade_point[i][j]=5;
            }
            else if(r.marks[i][j]>=45)
            {
                cout<<setw(12)<<"DD";
                r.grade_point[i][j]=4;
            }
            else
            {
                cout<<setw(12)<<"FF";
                r.grade_point[i][j]=0;
            }
        }
        cout<<endl;
    }

    int total_credit=0;
    //calculate total credit
    for(int i=0;i<3;i++)
    {
        total_credit=total_credit + r.credit[i];
    }

    //calculate sgpa
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<=1;j++)
        {
        r.sgpa= r.sgpa + (r.grade_point[i][j]*r.credit[i]);
        }
    }

    r.sgpa = r.sgpa/(total_credit*2);

    //print sgpa
    cout<<endl<<"SGPA : "<<fixed<<setprecision(2)<<r.sgpa;
}

int main()
{
    s.getdata_stu();
    s.getdata_result(r);

    //print marksheet
    cout<<endl<<"Result of the Student is generated successfully."<<endl;

    system("cls");

    cout<<setw(30)<<"CHARUSAT"<<endl;

    s.putdata_stu();

    cout<<setw(38)<<"Theory"<<setw(15)<<"Practical"<<endl;

    s.putdata_result(r);

    return 0;
}
