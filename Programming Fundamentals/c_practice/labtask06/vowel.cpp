#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Muhammad Athar Abbas" << endl;
cout << "    SP25-BSE-082   " << endl;
cout << "    Section - A    "  << endl;
cout << setw(25) << setfill('=') << '=' << endl;
char let;
cout << "Input the letter (lowercase): ";
cin >> let;
switch (let) {
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
cout << "Vowel Letter" << endl;
    break;
default:
    cout << "Consonant Letter" << endl;
}
return 0;
}
