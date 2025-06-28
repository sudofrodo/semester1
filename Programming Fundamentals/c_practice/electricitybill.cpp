#include <iostream>
using namespace std;
int main() {
int units_consumed;
cout << "Input units consumed:" << endl;
cin >> units_consumed;
float unit_price = 0;
int surcharge_per = 0;
if (units_consumed <= 300) {
    unit_price = 3;

}
else {
    unit_price = 3.5;
    surcharge_per = 5;
}
float bill = unit_price * units_consumed;
float net_bill = bill + (bill * surcharge_per / 100);
cout << "Your bill is " << net_bill << endl;
return 0;
}
