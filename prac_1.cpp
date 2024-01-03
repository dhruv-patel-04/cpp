#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    char s_id[8];
    string s_name, sub[3];
    int sem, credit=3, i,j;
    int marks[3][2];

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

    //input of subject names
    for(i=0;i<3;i++)
    {
     cout<<"Enter Name of subject "<<i+1<<" : ";
     getline(cin,sub[i]);
     fflush(stdin);
    }

    //entering marks of student
    for(i=0; i<3; i++)
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

    int grade_point[6],k=0;

    //print marksheet
    cout<<endl<<"Result of the Student is printed below."<<endl;
    cout<<endl;
    cout<<setw(30)<<"CHARUSAT"<<endl;
    cout<<"Student ID : "<<s_id<<endl;
    cout<<"Student Name : "<<s_name<<endl;
    cout<<"Semester : "<<sem<<endl;
    cout<<setw(40)<<"Theory"<<setw(15)<<"Practical"<<endl;

    //calculate grade_point and display grade
    for(i=0; i<3; i++)
    {
        cout<<setw(27)<<sub[i];
        for(j=0; j<=1; j++)
        {
            if(marks[i][j]>=80)
            {
                cout<<setw(12)<<"AA";
                grade_point[k]=10;
                k++;
            }
            else if(marks[i][j]>=73)
            {
                cout<<setw(12)<<"AB";
                grade_point[k]=9;
                k++;
            }
            else if(marks[i][j]>=66)
            {
                cout<<setw(12)<<"BB";
                grade_point[k]=8;
                k++;
            }
            else if(marks[i][j]>=60)
            {
                cout<<setw(12)<<"BC";
                grade_point[k]=7;
                k++;
            }
            else if(marks[i][j]>=55)
            {
                cout<<setw(12)<<"CC";
                grade_point[k]=6;
                k++;
            }
            else if(marks[i][j]>=50)
            {
                cout<<setw(12)<<"CD";
                grade_point[k]=5;
                k++;
            }
            else if(marks[i][j]>=45)
            {
                cout<<setw(12)<<"DD";
                grade_point[k]=4;
                k++;
            }
            else
            {
                cout<<setw(12)<<"FF";
                grade_point[k]=0;
                k++;
            }
        }
        cout<<endl;
    }

    float sgpa=0;

    //calculate sgpa
    for(k=0;k<6;k++)
    {
        sgpa= sgpa + (grade_point[k]*credit);
    }

    sgpa = sgpa/(credit*6);

    //print sgpa
    cout<<endl<<"SGPA : "<<fixed<<setprecision(2)<<sgpa;
}
