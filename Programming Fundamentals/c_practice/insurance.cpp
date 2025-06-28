#include <iostream>
using namespace std;
int main() {
string maritial_status,gender;
int age;
cout << "Maritial Status:" << endl;
cin >> maritial_status;
if (maritial_status == "married") {
    cout << "Your insurance is approved.";
}
else if (maritial_status == "unmarried") {

cout << "Gender: " << endl;
cin >> gender;
cout << "Age: " << endl;
cin >> age;
    if (gender == "male") {
        if (age > 30){
            cout << "Your insurance is approved.";
        }
        else {
            cout << "Your insurance is not approved.";
        }
        }
    else if(gender == "female") {
        if (age > 25) {
            cout << "Your insurance is approved.";
        } else {
            cout << "Your insurance is not approved.";
        }
    }
}
 return 0;
    }







