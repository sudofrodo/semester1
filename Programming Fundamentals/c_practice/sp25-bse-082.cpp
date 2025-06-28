#include <iostream>
#include <cmath>
using namespace std;
int main() {
float length_cm;
cout << "Input the length:" << endl;
cin >> length_cm;
float length_inch = length_cm / 2.54;
int length_inch2 = round(length_inch);
float length_yard = length_inch2 / 36;
float length_feet = (length_inch2 % 36) / 12;
float length_inches = length_inch2 % 12;
cout << length_yard << " yard(s) " << length_feet << " feet(foot) " << length_inches << " inch(es)" << endl;

return 0;


}
