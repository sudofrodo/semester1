#include <iostream>
using namespace std;
int multiple(int a , int b);
int main() {
int num1 , num2;
cout << "Input num 1 : ";
cin >> num1;
cout << "Input num 2 : ";
cin >> num2;
cout << multiple(num1 , num2);

return 0;
}
int multiple(int a , int b) {
    if (a == 0) {
        return 0;
    }
    else if (b % a == 0) {
        return 1;
    }
    else {
        return 0;
}
}
