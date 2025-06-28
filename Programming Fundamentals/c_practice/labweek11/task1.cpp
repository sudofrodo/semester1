#include <iostream>
#include <iomanip>
#define SIZE 20
using namespace std;
int main() {
int arr[SIZE];
int i , j = 0;
int neg_count = 0 , pos_count = 0 , odd_count = 0 , even_count = 0, zero_count = 0 , _max , _min;
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Enter values for array. " << endl;
for (i = 0; i <= SIZE - 1 ; i++) {
    cout << "Element " << i + 1 << " : ";
    cin >> arr[i];
}

for (j = 0; j <= SIZE - 1 ; ++j) {
    if(j == 0) {
     _min = arr[j];
     _max = arr[j];
    }
    if (arr[j] > 0) {
        ++pos_count;
    }
    if (arr[j] < 0) {
        ++neg_count;
    }
    if (arr[j] == 0) {
        ++zero_count;
    }
    if (arr[j] % 2 == 0) {
        ++even_count;
    }
    if (arr[j] % 2 != 0) {
        ++odd_count;
    }
    if (arr[j] > _max) {
        _max = arr[j];
    }
    if (arr[j] < _min) {
        _min = arr[j];
    }


}
cout << "Positive Values " << pos_count << endl;
cout << "Negative Values " << neg_count << endl;
cout << "Zero Values     " << zero_count << endl;
cout << "Odd values      " << odd_count << endl;
cout << "Even values     " << even_count << endl;
cout << "Largest Value   " << _max  << endl;
cout << "Smallest value  " << _min << endl;


return 0;
}
