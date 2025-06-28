#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double hypotenuse (double side1 , double side2);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Hypotenuse Triangle 1 = " << hypotenuse(3.0 , 4.0) << endl;
cout << "Hypotenuse Triangle 2 = " << hypotenuse(5.0 , 12.0) << endl;
cout << "Hypotenuse Triangle 3 = " << hypotenuse(8.0 , 15.0) << endl;
return 0;
}
double hypotenuse(double side1 , double side2){
return sqrt(side1 * side1 + side2 * side2);
}

