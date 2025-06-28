#include <iostream>
using namespace std;
int gcd_cal(int , int);
int main() {
cout << gcd_cal(11,32);
return 0;
}
int gcd_cal(int num1 , int num2) {
int small = num1 < num2 ? num1 : num2;
int i = 0;
for (i = small ; i >= 1 ; i--) {
    if (num1 % i == 0 && num2 % i == 0) {
        return i;
    }
}

}
