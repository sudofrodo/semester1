#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Muhammad Athar Abbas" << endl;
cout << "    SP25-BSE-082   " << endl;
cout << "    Section - A    "  << endl;
cout << setw(25) << setfill('=') << '=' << endl;
cout << "Input four numbers" << endl;
int num1,num2,num3,num4;

cout << "First num: ";
cin >> num1;
cout << "Second num: ";
cin >> num2;
cout << "Third num: ";
cin >> num3;
cout << "Fourth num: ";
cin >> num4;
cout << endl;
cout << setw(25) << setfill('=') << '=' << endl;
cout << "The Sum of the numbers is " << num1+num2+num3+num4 << endl;
cout << "The Product of the numbers is " << num1*num2*num3*num4 << endl;
cout << "The average of the numbers is " << (num1+num2+num3+num4) / 4 << endl;
int big = 0;
if (num1 >= num2) {
    big = num1;
}
if ( num3 >= big) {
    big = num3;
}
if (num4 >= big){
    big = num4;
}
cout << "The largest number is " << big << endl;
int small = 0;
if (num1 <= num2) {
    small = num1;
}
if (num3 <= small) {
    small = num3;
}
if (num4 <= small ){
    small = num4;
}
cout << "The smallest number is " << small << endl;


}

