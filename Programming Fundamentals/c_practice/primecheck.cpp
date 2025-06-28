#include <iostream>
using namespace std;
int main() {
int num , dividers;
dividers = 0;
cout << "Number " << endl;
cin >> num;
for (int divider = 1 ; divider <= num ; divider++){
   if(num % divider == 0){
    dividers++;
   }
}
    if (dividers == 2) {
        cout << "Prime";
    }
    else {
        cout << "Not Prime";
    }
return 0;
}

