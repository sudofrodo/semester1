#include <iostream>
#include <iomanip>
using namespace std;
int main (){
cout << "Muhammad Athar Abbas" << endl;
cout << "    SP25-BSE-082   " << endl;
cout << "    Section - A    "  << endl;
cout << setw(25) << setfill('=') << '=' << endl;
int no;
cout << "Input the Number: ";
cin >> no;
switch ((no > 0) - (no < 0)) { //condition check , if positive number is input , first condition is true and returns 1 , second condition is false returns 0 and 1 - 0 returns 1.
case 1:
cout << "Positive Number" << endl;
break;
case -1:
cout << "Negative Number" << endl;
break;
case 0:
cout << "Zero" << endl;
break;
}
return 0;
}
