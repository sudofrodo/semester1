#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Number to word" << endl;
int num;
cout << "Input a number (0-9)" << endl;
cin >> num;cout << setw(25) << setfill('=') << '=' << endl;
if (num == 0){
    cout << "Zero" << endl;
}

else if (num == 1) {
    cout << "One" << endl;
}
else if (num == 2) {
    cout << "Two" << endl;
}
else if (num == 3) {
    cout << "Three" << endl;
}
else if (num == 4) {
    cout << "Four" << endl;
}
else if (num == 5) {
    cout << "Five" << endl;
}
else if (num == 6) {
    cout << "Six" << endl;
}
else if (num == 7) {
    cout << "Seven" << endl;
}
else if (num == 8) {
    cout << "Eight" << endl;
}
else if (num == 9) {
    cout <<"Nine" << endl;
}
else{
    cout << "Please input a Number between 0 and 9" << endl;
}




return 0;
}
