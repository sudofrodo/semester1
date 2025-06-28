#include <iostream>
#include <cmath>
using namespace std;
int main() {
int inputNum, num ,remainder, result , digits , power;
digits = 0;
result = 0;
cout << "Enter an Integer : ";
cin >> inputNum;
num = inputNum;
while (num != 0) {
num /= 10;
++digits;
}
num = inputNum;
while (num != 0){
    remainder = num % 10;
    power = round(pow(remainder, digits));
    result += power;
    num /= 10;
}
if (result == inputNum) {
cout << inputNum << " is an armstrong number.";
}
else {
cout << inputNum << " is not an armstrong number.";
}
return 0;
}
