#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int main()
{
    char s_id[8];
    string s_name, sub[10];
    int sem, credit[10], i,j;
    int marks[10][2];

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

    int n;

    //input no of sub
    cout<<"Enter No of Subject : ";
    cin>>n;
    fflush(stdin);

    //input of subject names and credit
    for(i=0;i<n;i++)
    {
     cout<<"Enter Name of subject "<<i+1<<" : ";
     getline(cin,sub[i]);
     fflush(stdin);
     cout<<"Enter Credit : ";
     cin>>credit[i];
     fflush(stdin);
    }

    //entering marks of student
    for(i=0; i<n; i++)
    {
        for(j=0; j<1; j++)
        {
            cout<<"Enter Marks for Subject "<<i+1<<" : "<<endl;
            cout<<"Theory : ";
            cin>>marks[i][j];
            fflush(stdin);
            cout<<"Practical : ";
            cin>>marks[i][j+1];
            fflush(stdin);
        }
    }

    int grade_point[n*2][2];

    //print marksheet
    cout<<endl<<"Result of the Student is generated successfully."<<endl;

    system("cls");

    cout<<setw(30)<<"CHARUSAT"<<endl;
    cout<<"Student ID : "<<s_id<<endl;
    cout<<"Student Name : "<<s_name<<endl;
    cout<<"Semester : "<<sem<<endl;
    cout<<setw(38)<<"Theory"<<setw(15)<<"Practical"<<endl;

    //calculate grade_point and display grade
    for(i=0; i<n; i++)
    {
        cout<<left<<setw(35)<<sub[i];
        for(j=0; j<=1; j++)
        {
            if(marks[i][j]>=80)
            {
                cout<<setw(12)<<"AA";
                grade_point[i][j]=10;
            }
            else if(marks[i][j]>=73)
            {
                cout<<setw(12)<<"AB";
                grade_point[i][j]=9;
            }
            else if(marks[i][j]>=66)
            {
                cout<<setw(12)<<"BB";
                grade_point[i][j]=8;
            }
            else if(marks[i][j]>=60)
            {
                cout<<setw(12)<<"BC";
                grade_point[i][j]=7;
            }
            else if(marks[i][j]>=55)
            {
                cout<<setw(12)<<"CC";
                grade_point[i][j]=6;
            }
            else if(marks[i][j]>=50)
            {
                cout<<setw(12)<<"CD";
                grade_point[i][j]=5;
            }
            else if(marks[i][j]>=45)
            {
                cout<<setw(12)<<"DD";
                grade_point[i][j]=4;
            }
            else
            {
                cout<<setw(12)<<"FF";
                grade_point[i][j]=0;
            }
        }
        cout<<endl;
    }

    int total_credit=0;
    //calculate total credit
    for(i=0;i<n;i++)
    {
        total_credit=total_credit + credit[i];
    }

    float sgpa=0;

    //calculate sgpa
    for(i=0;i<n;i++)
    {
        for(j=0;j<=1;j++)
        {
         sgpa= sgpa + (grade_point[i][j]*credit[i]);
        }
    }

    sgpa = sgpa/(total_credit*2);

    //print sgpa
    cout<<endl<<"SGPA : "<<fixed<<setprecision(2)<<sgpa;
}
