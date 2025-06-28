#include <iostream>
using namespace std;
int main() {
cout << "Factorial Calculator" << endl;
cout << endl;
int num;
cout << "Enter the Number" << endl;
cin >> num;
int i = 1;
double ans = 1;
while (i <= num) {
    ans = ans * i;
    i++;
}
cout << "The factorial is " << ans << endl;
return 0;
}