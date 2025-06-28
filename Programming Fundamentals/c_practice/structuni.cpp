#include<iostream>
using namespace std;

struct Student
{
 int rollno;
 char name[20];
 float fee;

};

int main()
{
 Student st1 = {1,"Ali",20000.0};
 Student x[3]={1,"Ali",20000.0};
 Student *stptr;
 int i;
 cout<<"\nEnter roll number :";
 cin>>st1.rollno;
 cout<<"Enter name : ";
 cin.ignore();
 cin.get(st1.name,50);
 cout<<"Enter fee : ";
 cin>>st1.fee;
 cout<<"\nRoll number : "<<st1.rollno<<endl;
 cout<<"\nName : "<<st1.name;
 cout<<"\nFee : "<<st1.fee;

 //Getting values using array
 for(i=0;i<3;i++)
 {
    cout<<"\nEnter roll number :";
    cin>>x[i].rollno;
    cout<<"\nEnter name : ";
    cin.ignore();
    cin.get(x[i].name,50);
    cout<<"\nEnter fee : ";
    cin>>x[i].fee;
}
for(i=0;i<3;i++)
 {
    cout<<"\nRoll number : "<<x[i].rollno;
    cout<<"\nName : "<<x[i].name;
    cout<<"\nFee : "<<x[i].fee;
}
//using pointer
stptr = &st1;

 cout<<"\nRoll number : "<<stptr->rollno;
 cout<<"\nName : "<<stptr->name;
 cout<<"\nFee : "<<stptr->fee;

return 0;
}



