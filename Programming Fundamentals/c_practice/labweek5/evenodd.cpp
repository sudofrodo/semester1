#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Even or Odd" << endl;
int x;
cout << "Input the number to check" << endl;
cin >> x;
cout << setw(25) << setfill('=') << '=' << endl;
if  (x % 2 == 0){
        cout << "Number is Even" << endl;
}
else{
        cout << "Number is Odd" << endl;
}

return 0;}
