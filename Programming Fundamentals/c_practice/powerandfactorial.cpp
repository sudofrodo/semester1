#include <iostream>
using namespace std;
int main() {
cout << "Factorial Calculator" << endl;
cout << endl;
int num;
cout << "Enter the Number" << endl;
cin >> num;
int i = 1;
int ans = 1;
while (i <= num) {
    ans = ans * i;
    i++;
}
cout << "The factorial is " << ans << endl;
cout << endl;
cout << "Power" << endl;
cout << endl;
int base;
cout << "Enter the Base Number" << endl;
cin >> base;
int pow;
cout << "Enter the power" << endl;
cin >> pow;
int n_i = 1;
int n_ans = 1;
while (n_i <= pow) {
    n_ans = base * n_ans;
    n_i++;
}
cout << n_ans << endl;
return 0;
}
