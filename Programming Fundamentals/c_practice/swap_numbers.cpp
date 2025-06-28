#include <iostream>
using namespace std;
float percentage_calculator();
int main() {
// swapping numbers with a variable
int a = 20;
int b = 25;
int c = a;
a = b;
b = c;
cout << "a = " << a << endl;
cout << "b = " << b << endl;
// abstract swapping
cout << "number 1" << endl;
int one;
cin >> one;
cout << "number 2" << endl;
int two;
cin >> two;
cout << "Swapped numbers" << endl;
one = one + two;
two = one - two;
one = one - two;
cout << "one = " << one << endl;
cout << "two = " << two << endl;
return 0;
}
