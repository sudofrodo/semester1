#include <iomanip>
#include <iostream>
using namespace std;
int main() {
int num;
cout << "Enter a positive integer: ";
cin >> num;
int i = 1;
while (i <= 10) {
     cout << num << " x " << setw(2) << right << i << " = " << setw(2) << num*i << endl;
     i++;
}
return 0;
}
