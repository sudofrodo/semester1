#include <iostream>
using namespace std;
int main() {
int value;
cout << "Input the number" << endl;
cin >> value;
cout << endl;
switch (value){
case 1:
    cout << "Cooking Rice";
    break;
case 2:
    cout << "Cooking Chicken";
    break;
case 3:
    cout << "Making Pizza";
    break;
case 4:
    cout << "Frying Wings";
    break;
default:
    cout << "We don't have your desire product.";
}
cout << endl;

return 0;
}
