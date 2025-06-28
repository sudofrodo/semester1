#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Input three numbers" << endl;
int num1,num2,num3;

cout << "First num: ";
cin >> num1;
cout << "Second num: ";
cin >> num2;
cout << "Third num: ";
cin >> num3;
cout << endl;
cout << setw(25) << setfill('=') << '=' << endl;
cout << "The Sum of the numbers is " << num1+num2+num3 << endl;
cout << "The Product of the numbers is " << num1*num2*num3 << endl;
cout << "The average of the numbers is " << (num1+num2+num3) / 3 << endl;
int big = 0;
if (num1 >= num2) {
    big = num1;
}
if ( num3 > big) {
    big = num3;
}
//int big = (num1 >= num2) ? num1 : num2;
//int bigger = (big >= num3) ? big : num3;
cout << "The largest number is " << big << endl;
int small = (num1 <= num2) ? num1 : num2;
int smaller = (small <= num3) ? small : num3;
cout << "The smallest number is " << smaller << endl;


}
