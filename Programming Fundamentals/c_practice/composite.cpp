#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Muhammad Athar Abbas" << endl;
cout << "   Sp25-bse-082" << endl;
cout << "    Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << endl;
int start;
int last;
cout << "Enter the start of the range: ";
cin >> start;
while (start < 0) {
    cin.clear();
    cin.ignore();
    cout << "Invalid range. Please ensure both numbers are positive integers and start is less than or equal to the end."<< endl;
    cout << "Enter the start of the range: ";
    cin >> start;
} ;
cout << "Enter the end of the range: ";
cin >> last;
while (last < 0 || start > last) {
    cin.clear();
    cin.ignore();
    cout << "Invalid range. Please ensure both numbers are positive integers and start is less than or equal to the end." << endl;
    cout << "Enter the end of the range: ";
    cin >> last;
}
cout << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << endl;
cout << "Composite numbers between " << start << " and " << last << " are: ";
int com_sum = 0;
int number = start;
for ( number ; number <= last ; number++ ) {
        for (int divider = 2 ; divider < number ; divider++) {
            if ( number % divider == 0) {
                cout <<number << " ";
                com_sum += number;
                break;
                }
            }
}
cout << endl;
cout << "The sum of Composite number is " << com_sum << endl;
return 0;
}
