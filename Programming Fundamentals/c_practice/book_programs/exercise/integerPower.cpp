#include <iostream>
#include <iomanip>
using namespace std;
int integerPower(int power , int base);
int main() {

int power , base;
cout << "Input Base ";
cin >> base;
cout << endl;
cout << "Input Exponent ";
cin >> power;
cout << endl;
cout << "Answer " << integerPower(power , base);
cout << endl;
return 0;
}
int integerPower(int power , int base) {
int i = 0;
int ans = 1;

for (i = 1 ; i <= power ; i++) {
    ans = ans * base;
}
return ans;
}
