#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int start;
int last;
do  {
    cout << "Enter the start of the range (only positive numbers) : ";
    cin >> start;
    cin.clear();
    cin.ignore();
} while (start < 0);
do {
    cout << "Enter the end of the range(only positive number , greater or equal to start): ";
    cin >> last;
    cin.clear();
    cin.ignore();
} while (last < 0 || start > last);
<
cout << start << endl;
cout << last << endl;

cout << setw(27) << setfill('=') << '=' << endl;




return 0;
}

