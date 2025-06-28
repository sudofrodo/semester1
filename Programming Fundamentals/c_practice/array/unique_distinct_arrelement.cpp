#include <iostream>
#include <iomanip>
using namespace std;
int unique_only(int arr[] , int n);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;

int n;
cout << "What is size your array : ";
cin >> n;
int arr[n];
cout << "Enter numbers : " << endl;
for (int i = 0 ; i < n ; i++) {
    cout << "element - " << i << " : ";
    cin >> *(arr + i);
}
cout << "Unique elements are : ";
unique_only(arr , n);
}
int unique_only(int arr[] , int n) {
for (int i = 0 ; i < n ; i++) {
int key = arr[i];
int counter = 0;
    for (int j = 0 ; j < n ; j++) {
        if (key == arr[j]) {
            counter++;
        }
    }
    if (counter == 1) {
        cout << arr[i] << " "  ;
    }
}

return 0;
}

