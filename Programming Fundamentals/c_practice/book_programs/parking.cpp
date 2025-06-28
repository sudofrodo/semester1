#include <iostream>
using namespace std;
double chargecal(int hours);
int main(){
int inhours;
while (inhours != -1){
cout << "Enter the number of hours " << endl;
cin >> inhours;
cout << "Parking charges : " << chargecal(inhours) << " dollars" << endl;
}

return 0;
}
double chargecal(int hours) {
double fixcharge = 2.00;
double pluscharge = 0.5;
double charge;
if (hours <= 3.00) {
    charge = fixcharge;
}
else if ( hours > 3.00 && hours < 10.00) {
    charge = fixcharge + pluscharge * (hours - 3);
}
else {
    charge = 10.00;
}
return charge;
}
