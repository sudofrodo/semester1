#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int num;
cout << "Enter a positive integer: ";
cin >> num;
int counter = 1;
    while (num != 2) {
        if (num % 2 == 0) {
        num = num / 2;
        cout << "Next value is " << num << endl;
        }
        else {
            num = (num * 3) + 1;
            cout << "Next value is " << num << endl;
        }
    counter++;
    }
cout << "Final value 1" << endl;
cout << "Number of steps " << counter << endl;

return 0;
}
