#include <iostream>
#include <fstream>
using namespace std;
int main() {
int rollno;
string name;
int marks;
ofstream write;
write.open("names.txt");
if (!write) {
    cout << "Unable to create file\n";
    return 1;
}
cout  << "File created." << endl;
write.clear();
cout << "Enter 0 at Roll no to close : " << endl;
cout << "Enter Roll no : ";
cin >> rollno;
write << rollno << "  ";
while (rollno != 0) {
cout << "Enter name : ";
cin >> name;
write << name << "  ";
cout << "Enter marks : ";
cin >> marks;
write << marks;
write << endl;
cout << endl;
cout << "Enter Roll no : ";
cin >> rollno;
if (rollno != 0) {
write << rollno << "  ";
}
}
write.close();
ifstream read("names.txt");
if (!read) {
    cout << "Unable to open file\n";
    exit(0);
}
cout << "Reading file : " << endl;
cout <<"Rollno"<< "   " <<"Name"<< "   " <<"Marks" << endl;
read >> rollno;
read >> name;
read >> marks;
while(!read.eof()) {

    cout << rollno << "      " << name << "      " << marks << endl;
    read >> rollno >> name >> marks;
}
read.close();
return 0;
}





