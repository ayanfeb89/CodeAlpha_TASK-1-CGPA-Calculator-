#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<limits>
using namespace std;
int main()
{
    int choice;
    do{
    cout<<"Choose any one: "<<endl<<
    "1. Add your semester details"<<endl<<
    "2. View your CGPA"<<endl
    <<"3. Quit program"<<endl<<"Types here: ";
    cin>>choice;
    if(choice<1 || choice>3){
        cout<<"Error: Invalid option! please Enter 1,2 or 3."<<endl;
    }
    }while(choice<1 || choice>3);
    while(choice!=3)
    {
    if(choice==1)
    {
         int st;
    cout<<"Enter the number of students: ";
    cin>>st;
    double cgpa[30];
    string roll[30];
    string subject[30][30][30];
      string grades[30][30][30];
      float gps[30][30][30];
      int credit_hour[30][30][30];
      int ccount[30][30];
      int scount[30];
      double gpa[30][30];
      for(int i=0;i<st;i++)
      {
          int credit_hour_all=0;
    float gps_all=0;
          cout<<"Enter the Roll number of student "<<i+1<<": ";
          cin>>roll[i];
    int c,s;
    cout<<"Enter the number of semester of "<<roll[i]<<": ";
    cin>>s;
    scount[i]=s;

    for(int j=0;j<s;j++)
    {
        cout<<"Enter the Number of course in Semester "<<j+1<<" of Roll number "<<roll[i]<<": ";
        cin>>c;
        ccount[i][j]=c;
        int total_credit_hour=0;
        float total_gps=0;

        for(int k=0;k<c;k++)
        {
            cout<<"Enter the name of subject "<<k+1<<" of Semester "<<j+1<<" of Roll number "<<roll[i]<<": ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,subject[i][j][k]);
            cout<<"Enter the Credit Hour of "<<subject[i][j][k]<<" of Semester "<<j+1<<" of Roll number "<<roll[i]<<": ";
            cin>>credit_hour[i][j][k];
            while(credit_hour[i][j][k]<0)
            {
                cout<<"Error, credit hour can not be less than zero"<<endl;
                cout<<"Enter the Credit Hour of "<<subject[i][j][k]<<" of Semester "<<j+1<<" of Roll number "<<roll[i]<<": ";
                cin>>credit_hour[i][j][k];
            }
            cout<<"Enter the Grade of "<<subject[i][j][k]<<" of Semester "<<j+1<<" of Roll number "<<roll[i]<<" i.e(A,A-,B+,B.....)"<<": ";
            cin>>grades[i][j][k];
            if(grades[i][j][k]=="A" || grades[i][j][k]=="a")
            {
                gps[i][j][k]=4.0;
            }
            else if(grades[i][j][k]=="A-" || grades[i][j][k]=="a-")
            {
                gps[i][j][k]=3.7;
            }
            else if(grades[i][j][k]=="B+" || grades[i][j][k]=="b+")
            {
                gps[i][j][k]=3.3;
            }
            else if(grades[i][j][k]=="B" || grades[i][j][k]=="b")
            {
                gps[i][j][k]=3.0;
            }
            else if(grades[i][j][k]=="B-" || grades[i][j][k]=="b-")
            {
                gps[i][j][k]=2.7;
            }
            else if(grades[i][j][k]=="C+" || grades[i][j][k]=="c+")
            {
                gps[i][j][k]=2.3;
            }
            else if(grades[i][j][k]=="C" || grades[i][j][k]=="c")
            {
                gps[i][j][k]=2.0;
            }
            else if(grades[i][j][k]=="C-" || grades[i][j][k]=="c-")
            {
                gps[i][j][k]=1.7;
            }
            else if(grades[i][j][k]=="D" || grades[i][j][k]=="d")
            {
                gps[i][j][k]=1.0;
            }
            else if(grades[i][j][k]=="F" || grades[i][j][k]=="f")
            {
                gps[i][j][k]=0.0;
            }else{
            cout<<"Error: Invalid Grade"<<endl;
            cout<<"Enter the Grade of "<<subject[i][j][k]<<" of Semester "<<j+1<<" of Roll number "<<roll[i]<<" i.e(A,A-,B+,B.....)"<<": ";
            cin>>grades[i][j][k];
            k--;
            continue;
            }
            total_credit_hour+=credit_hour[i][j][k];
            total_gps+=gps[i][j][k]*credit_hour[i][j][k];
        }
        gpa[i][j]=total_gps/total_credit_hour;
        credit_hour_all+=total_credit_hour;
        gps_all+=total_gps;
    }
    cgpa[i]=gps_all/credit_hour_all;
    ifstream infile("Result.txt");
string rollno;
bool found=false;
while(infile>>rollno)
{
    if(rollno==roll[i]+":")
    {
        found=true;
        break;
    }
}
infile.close();

if(found)
{
    cout<<"Error, Invalid Roll number"<<endl;
}
else{
    ofstream outfile("Result.txt",ios::app);
    outfile<<roll[i]<<": "<<cgpa[i]<<endl;
    outfile.close();
    cout<<roll[i]<<" "<<"CGPA stored."<<endl;
}
}
for(int i=0;i<st;i++)
{
   cout<<"For->"<<roll[i]<<endl;
   cout<<"-------------------------------------------------------------------"<<endl;
   for(int j=0;j<scount[i];j++)
   {
       cout<<"-----> Semester "<<j+1<<"<------"<<endl;
       cout<<left<<setw(25)<<"Subject"<<setw(15)<<"Credit Hour"<<setw(10)<<"Grades"<<setw(10)<<"Gps"<<endl;
       for(int k=0;k<ccount[i][j];k++)
       {
        cout<<left<<setw(25)<<subject[i][j][k]<<setw(15)<<credit_hour[i][j][k]<<setw(10)<<grades[i][j][k]<<setw(10)<<gps[i][j][k]<<endl;
       }
       cout<<"GPA of Semester "<<j+1<<" of "<<roll[i]<<" is: "<<gpa[i][j]<<endl;
       cout<<endl;
   }
   cout<<"CGPA of "<<roll[i]<<" is: "<<cgpa[i]<<endl;
   cout<<"-------------------------------------------------------------------"<<endl;
   cout<<endl;
}
}
    if(choice==2)
    {
        string newroll;
        cout<<"Enter a roll number: ";
        cin>>newroll;
        ifstream infile("Result.txt");
        string rollno;
        bool found=false;
        double cgp;
        while(infile>>rollno>>cgp)
        {
            if(rollno==newroll+":")
            {
                cout<<"The CGPA of "<<newroll<<": "<<cgp<<endl;
                found=true;
                break;
            }
        }
        infile.close();
        if(!found)
        {
            cout<<"Error, Roll number not found."<<endl;
        }
    }
    cout<<"Choose any one: "<<endl<<
    "1. Add your semester details"<<endl<<
    "2. View your CGPA"<<endl
    <<"3. Quit program"<<endl<<"Types here: ";
    cin>>choice;
}
cout<<"Thank you for visiting, Goodbye"<<endl;
return 0;
}
