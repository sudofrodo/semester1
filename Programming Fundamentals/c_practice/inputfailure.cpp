#include <iostream>
using namespace std;
int main() {
int x;
cout << "Input the number: " << endl;
cin >> x;
while (!cin) {
    cin.clear();
    cin.ignore();
    cout << "Enter x again: " << endl;
    cin >>x;


}
cout << endl;
cout << x << endl;
return 0;
}
