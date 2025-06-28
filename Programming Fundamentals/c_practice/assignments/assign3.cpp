#include <iostream>
#include <iomanip>
using namespace std;
int duplicate(int a[] , int n);
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
cout << endl <<"The number of duplicate elements is " << duplicate(arr , n) << endl;
return 0;
}
int duplicate(int a[] , int n) {
int duplicates = 0;

for (int i = 0 ; i < n ; i++) {
    bool isDuplicate = false;

    for(int j = 0 ; j < i ; j++) {
        if (a[i] == a[j]) {
            isDuplicate = true;
            break;
        }
    }

    if (isDuplicate) {
        continue;
    }
    int _count = 0;
    for (int j = i + 1 ; j < n ; j++) {
        if (a[i] == a[j]) {
            _count++;
        }
    }

    if (_count > 0) {
        duplicates++;
    }
}
return duplicates;
}
