#include <iostream>
using namespace std;
int main () {
int value1 , value2;
cout <<"Input Value 1: ";
cin >> value1;
cout <<"Input Value 2: ";
cin >> value2;
int big = (value1 >= value2) ? value1 : value2;
cout << "Big value is " << big << endl;
return 0;
}
