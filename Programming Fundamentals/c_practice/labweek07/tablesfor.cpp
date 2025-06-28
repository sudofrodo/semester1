#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int num;
cout << "Enter a positive integer: ";
cin >> num;
int i = 1;
for (i ; i <= 10 ;i++) {
    cout << num << " x " << setw(2) << right << i << " = " << setw(2) << num*i << endl;
}
return 0;
}
