#include <iostream>
#include <iomanip>
using namespace std;
int main() {
//prices are per kgs
int rice_price = 200;
int floor_price = 150;
int sugar_price = 110;
int oil_price = 520;
cout <<"Rice Bought:" << endl;
int rice_bought;
cin >> rice_bought;
cout << "Floor Bought: " << endl;
int floor_bought;
cin >> floor_bought;
cout << "Sugar Bought: " << endl;
int sugar_bought;
cin >> sugar_bought;
cout << "Oil Bought: "<< endl;
int oil_bought;
cin >> oil_bought;
int total = (rice_bought * rice_price) + (oil_bought * oil_price) + (sugar_bought * sugar_price) + (floor_bought * floor_price);

cout << "Your total is " << total << endl;
int discount = 0;
if (total > 5000) {
    discount = 10;
    cout << "Discount applied : 10%" << endl;
    cout << "Your net total is " << total - (total * discount / 100) << endl;
}
else {
    cout << "Discount applied : 0%" << endl;
    cout << "Your net total is " << total << endl;
}
return 0;
}
