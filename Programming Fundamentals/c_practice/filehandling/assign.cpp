#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
int arrayToDigit(int arr[3]);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
string reg_no , name , section;
cout << "Please enter Registration no. (in format SP25-BSE-082)\n";
cin >> reg_no;
cout << "Enter your Section (as SP25-A)\n";
cin >> section;
cout << "Enter your Name (as Athar Abbas)\n";
cin.ignore();
getline(cin , name);
int rollno_arr[3] = {reg_no[9] - '0', reg_no[10] - '0', reg_no[11] - '0'}; /*get roll no, which is last 3 characters of reg. no string.
'-0' to convert char to int. */
int rollno = arrayToDigit(rollno_arr);

//creating file for writing info.
ofstream write;
write.open("original.txt");
if (!write) {
    cout << "Unable to open file!!!\n";
    return 1;
}
cout << "File successfully created." << endl;

write << "Registration number:  " << reg_no << "   ";
write << "Name:  " << name << "   ";
write << "Section:  " << section << "   ";
write << endl;

write.close();
cout << "Data written successfully in original.txt" << endl;

ifstream read;
read.open("original.txt");
if (!read) {
    cout << "Unable to open file\n";
    exit(0);
}
//reading file to encrypt the data and store it in new 001.txt
ofstream encrypt;
encrypt.open("001.txt");
char ch;
while (!read.eof()) {
    read.get(ch);
    encrypt.put(ch + rollno); //encrypting
}
encrypt.close();
read.close();
cout << "Data is encrypted and stored successfully in 001.txt\n";

cout << "Data after decrypting from file 001.txt\n";
//reading encrypted file and output decrypted data on console
char a;
ifstream decrypt("001.txt");
if (!decrypt) {
    cout << "Unable to open file\n";
    exit(0);
}
while(!decrypt.eof()) {
decrypt.get(a);
cout << char(a - rollno);

}
decrypt.close();
cout << "\nProgram ends here";
return 0;
}
int arrayToDigit(int arr[3]) {
    int result = 0;
    for (int i = 0 ; i <= 2 ; i++) {
        result = result * 10 + arr[i];
    }
    return result;
}
