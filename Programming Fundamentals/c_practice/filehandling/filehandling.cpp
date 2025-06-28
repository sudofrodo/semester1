#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main() {
int i = 0;
char ch;
char str[] = "Time is a great teacher, but unfortunately"
"it kills all its pupils.";
ofstream write;
write.open("test.txt");
if (!write) {
    cout << "Unable to open file!!!\n";
    return 1;
}
while (str[i] != '\0') {
    write.put(str[i]);
    i++;
}
write.close();
cout << "File written\n";
ifstream read("test.txt");
if(!read) {
    cout << "Unable to open file!!!\n";
    return 1;
}
while(!read.eof()) {
    read.get(ch);
    cout << ch;
}
read.close();
cout << endl << endl;
//accounts
int accountno;
string name;
float balance;
ofstream file("person.dat");
if (!file) {
    cout << "Cannot open file person.dat";
    return 1;
}
cout << "Enter account number or 0 to end : ";
cin >> accountno;
while (accountno != 0) {
    cout << "Enter name : ";
    cin.ignore();
    cin >> name;
    cout << "Enter balance : ";
    cin >> balance;
    file << accountno;
    file << name << "  ";
    file << balance << "  ";
    cout << "Enter account number or 0 to end : ";
    cin >> accountno;
}
file.close();
ifstream infile("person.dat");
if (!infile) {
    cout << "Cannot open file person.dat";
    exit(0);
}
infile >> accountno;
infile  >> name;
infile >> balance;
while (!infile.eof()) {
cout << accountno << endl;
cout << name << endl;
cout << balance << endl;
infile>>accountno;
infile >> name;
infile >> balance;
}
infile.close();
return 0;
}
