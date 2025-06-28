#include <iostream>
#include <iomanip>
#define SIZE 10
using namespace std;
int main() {
int i, j ;
int counter = 0;
int key;
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Enter values for array." << endl;
int arr[SIZE];
for (i = 0; i <= SIZE - 1 ; i++) {
    cout << "Element " << i + 1 << " : ";
    cin >> arr[i];
}
cout << "Please input number to find " << endl;
cin >> key;
for (j = 0 ; j <= SIZE - 1 ; j++) {
    if (key == arr[j] ) {
        counter++;
    }
}
if (counter > 0) {
        cout << "Integer " << key << " is present in array." << endl;
        cout << "Integer " << key << " appears " << counter << " times in array." << endl;
} else {
cout << "This Integer is not present in array." << endl;
}
return 0;
}
