#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "Input the three angles" << endl;
double num1,num2,num3;

cout << "Angle 𝜶: ";
cin >> num1;
cout << "Angle 𝛃: ";
cin >> num2;
cout << "Angle 𝜸: ";
cin >> num3;
double sum = num1 + num2 + num3;
cout << setw(25) << setfill('=') << '=' << endl;
if (sum == 180 ) {
    cout << "Triangle is Valid" << endl;
} else {
    cout << "Invalid Triangle" << endl;
}



}
