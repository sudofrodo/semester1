#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int num , sum , counter;
cout << "Enter a positive integer: ";
cin >> num;
counter = 0;
sum = num + 1;
while (num != -1) {
    cout << "Enter a positive integer: ";
    cin >> num;
    sum += num;
    counter++;
}
cout << "The sum of the numbers is " << sum << endl;
cout << "The average of the number is " << sum / double(counter) << endl;
return 0;
}
