#include <iostream>
#include <iomanip>
using namespace std;
int main() {
char grade;
int sub , grace;

cout << "What is your Grade : ";
cin >> grade;
cout << "Number of subjects you have failed in : ";
cin >> sub;
grace = 0;
switch (grade) {
case 'A':
    if (sub <= 3) {
        grace = 5 * sub;
    }
    break;

case 'B':
    if (sub <= 2) {
        grace = 4 * sub;
    }
    break;
case 'C':
    if (sub == 1){
        grace = 5 * sub;
    }

}
cout << "Your grace marks are " << grace << endl;
return 0;}
