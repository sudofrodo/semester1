#include <iostream>
#include <iomanip>
#define SIZE 10
using namespace std;
int main() {
int arr[SIZE];
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Enter values for array." << endl;
int i = 0 , j = 0;
for (i = 0; i <= SIZE - 1 ; i++) {
    cout << "Element " << i + 1 << " : ";
    cin >> arr[i];
}
int arr2[SIZE];
for (j = 0 ;  j <= SIZE - 1 ; ) {
     for (i = SIZE - 1 ; i >= 0; --i) {
      arr2[j] = arr[i];
      j++;
    }
}
cout << "Array 1 : ";
for (i = 0; i <= SIZE - 1 ; i++) {
    cout << arr[i] << "  ";
}
cout << endl;
cout << "Array 2 : ";
for (i = 0; i <= SIZE - 1 ; i++) {
    cout << arr2[i] << "  ";
}
return 0;
}
