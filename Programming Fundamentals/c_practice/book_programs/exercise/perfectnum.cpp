#include <iostream>
using namespace std;
int perfect_num(int num);
int main() {
int _num;
cout << "Input number to check ";
cin >> _num;
cout << perfect_num(_num);
cout << endl;
cout << "Perfect number between 1 and 1000";
cout << endl;
int x;
for (x=1 ; x <= 1000 ; x++) {
    if (perfect_num(x) == 1) {
        cout << x << "  ";
    }
}
return 0;
}
int perfect_num(int num) {
int i = 0;
int sum = 0;
cout << "Factors ";
for (i = 1 ; i <= num - 1 ; i++) {
    if (num % i == 0) {
        sum += i;
        cout << i << " ";
    }
}
cout << endl;
if (sum == num) {
    return 1;
}
else {
    return 0;
}
}


