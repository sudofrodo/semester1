#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Muhammad Athar Abbas" << endl;
cout << "    SP25-BSE-082   " << endl;
cout << "    Section - A    "  << endl;
cout << setw(25) << setfill('=') << '=' << endl;
int num1,num2;
int option;

cout << endl;
cout << "Input Num 1: " << endl;
cin >> num1;

cout << "Input Num 2: " << endl;
cin >> num2;

cout << "What operation you want to perform?" << endl;
cout << "For addition : 1\nFor subtraction : 2\nFor multiplication : 3\nFor Division : 4\nFor Remainder : 5\nFor Factorial : 6\nFor Power : 7\n" << endl;
cin >> option;
cout << endl;
switch (option) {
case 1 :
    cout << "The sum of two numbers is " << num1 + num2;
    break;
case 2:
    cout << "The difference of two number is ";
    cout << num1 - num2;
    break;
case 3:
    cout << "The product of two numbers is " << num1 * num2;
    break;
case 4:
    cout << "The division of two numbers results in " << num1 / num2;
    break;
case 5:
    cout << "The remainder is " << num1 % num2;
    break;
case 6: {
int i = 1;
int ans = 1;
while (i <= num1) {
    ans = ans * i;
    i++;
}
cout << "The factorial of "<< num1 << " is " << ans << endl;
int j = 1;
int ans2 = 1;
while (j <= num2) {
    ans2 = ans2 * j;
    j++;
}
cout << "The factorial of " << num2 <<  " is " << ans2 << endl;}
break;
case 7:
{
    int base = num1;
int pow = num2;
int n_i = 1;
int n_ans = 1;
while (n_i <= pow) {
    n_ans = base * n_ans;
    n_i++;
}
cout << "The power of " <<num1<< " raised to " << num2 << " is " << n_ans << endl;}
default:
    {
    cout << "Invalid Input" << endl;
    }
}

return 0;
}
