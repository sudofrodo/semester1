#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct clientData {
int acctNum;
char lastName[15];
char firstName[10];
double balance;
};
int main() {
cout << "Hello" << endl;
int i;
clientData client = {0,"","",0.0};
fstream cf;
//cf.open("credit.dat", ios::out | ios::binary);
//if (!cf) {
//    cout << "File can not be opened" << endl;
//
//} else {
//    cout<<"Enter account number ( 1 to 100, 0 to end input )\n? ";
//
//cin >> client.acctNum ;
//while (client.acctNum != 0) {
//    cout<< "Enter lastname, firstname, balance\n? " ;
//    cin >> client.lastName >> client.firstName >> client.balance;
//    cf.seekg((client.acctNum - 1) * sizeof(struct clientData));
//
//    cf.write((char*)&client, sizeof(clientData));
//
//    cout << "Enter account number\n?";
//    cin >> client.acctNum;
//
//}
//    cf.close();
//}

cf.open("credit.dat", ios::in | ios::binary);
if (!cf) {
    cout << "File could not be opened";
} else {
    cout<<setw(6)<<"Acct"<<setw(16)<<"Last Name"<<setw(11)<<"FirstName"<<setw(10)<<"Balance"<<endl;
    cf.read((char*)&client, sizeof(clientData));
    while (!cf.eof()) {
        if (client.acctNum != 0) {
cout<<setw(6)<<client.acctNum<<setw(16)<<client.lastName<<setw(11)<<client.firstName<<setw(10)<<client.balance<<endl;
        }
        cf.read((char *)&client, sizeof(clientData));
    }
    cf.close();
}
return 0;
}
