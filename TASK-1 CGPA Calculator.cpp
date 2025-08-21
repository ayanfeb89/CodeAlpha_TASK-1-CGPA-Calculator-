#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
      string subject[50][50];
      float grades[50][50];
      int credit_hour[50][50];
      int ccount[50];
    double gpa[50];
    int c,s;
    int credit_hour_all=0;
    float grades_all=0;
    cout<<"Enter the number of semester: ";
    cin>>s;

    for(int i=0;i<s;i++)
    {
        cout<<"Enter the Number of course in Semester "<<i+1<<": ";
        cin>>c;
        ccount[i]=c;
        int total_credit_hour=0;
        float total_grades=0;

        for(int j=0;j<c;j++)
        {
            cout<<"Enter the name of subject "<<j+1<<" of Semester "<<i+1<<": ";
            cin.ignore();
            getline(cin,subject[i][j]);
            cout<<"Enter the Credit Hour of "<<subject[i][j]<<" of Semester "<<i+1<<": ";
            cin>>credit_hour[i][j];
            cout<<"Enter the Grade of "<<subject[i][j]<<" of Semester "<<i+1<<": ";
            cin>>grades[i][j];
            total_credit_hour+=credit_hour[i][j];
            total_grades+=grades[i][j]*credit_hour[i][j];
        }
        gpa[i]=total_grades/total_credit_hour;
        grades_all+=total_grades;
        credit_hour_all+=total_credit_hour;
}
for(int i=0;i<s;i++){
    cout<<"  ------> For Semester "<<i+1<<"<------"<<endl;
cout<<left<<setw(20)<<" Subject"<<setw(15)<<"Credit Hour"<<setw(10)<<"Grades"<<endl;
for(int j=0;j<ccount[i];j++)
{
  cout<<left<<setw(20)<<subject[i][j]<<setw(15)<<credit_hour[i][j]<<setw(10)<<grades[i][j]<<endl;
}
cout<<endl;
cout<<"Your GPA of Semester "<<i+1<<"-> "<<gpa[i]<<endl;
cout<<endl;
}
cout<<"Your Overall CGPA is-> "<<grades_all/credit_hour_all<<endl;
}

