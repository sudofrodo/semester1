#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Muhammad Athar Abbas" << endl;
cout << "    SP25-BSE-082   " << endl;
cout << "    Section - A    "  << endl;
cout << setw(25) << setfill('=') << '=' << endl;
char x;
cout << "Input the character" << endl;
cin >> x;
cout << endl;
cout << setw(25) << setfill('=') << '=' << endl;
cout << endl;
if (isupper(x)) {
    cout << "Uppercase Alphabet" << endl;

} else {
cout << "Lowercase Alphabet" << endl;
}
return 0;
}
