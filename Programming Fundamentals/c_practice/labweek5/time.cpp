#include <iostream>
#include <iomanip>
using namespace std;
int main () {
int itimeh , itimem , itimes;
cout << "Input the time in 24 hour format" << endl;
cout << "Hours: ";
cin >> itimeh;
cout << "Minutes: ";
cin >> itimem;
cout << "Seconds: ";
cin >> itimes;
cout << endl;
cout << setw(25) << setfill('=') << '=' << endl;
cout << endl;
cout << "Time in 12 hour format" << endl;
int ntimeh;
if (itimeh <= 12) {
    cout << itimeh << ":" << itimem << ":" << itimes << endl;
}
if (itimeh > 12) {
    ntimeh = itimeh - 12;
    cout << ntimeh << ":" << itimem << ":" << itimes << endl;
}



return 0;
}
