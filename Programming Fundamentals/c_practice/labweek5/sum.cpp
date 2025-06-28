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
int sum = 0;
if (num1 >= 0) {
    sum += num1;
}
if (num2 >= 0){
    sum += num2;

}
if (num3 >= 0) {
    sum += num3;
}

cout << "The Sum of the positive integers is " << sum << endl;
return 0;
}
