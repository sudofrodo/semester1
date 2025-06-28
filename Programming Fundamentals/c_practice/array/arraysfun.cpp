#include <iostream>
#include <iomanip>
#define SIZE 5
using namespace std;
void addition(int arr[]);
void subtraction(int arr[] , int _size);
void multiply(int arr[SIZE]);
int main() {
int arr[SIZE] = {1,2,3,4,5};
addition(arr);
cout << "Modified array ";
int i = 0;
for (i= 0; i < SIZE ; i++ ) {
    cout << arr[i] << "  ";
}
cout << "Same array ";
subtraction(arr , SIZE);
for (i= 0; i < SIZE ; i++ ) {
    cout << arr[i] << "  ";
}
cout << endl;
cout << "Multiplied ";
multiply(arr);
for (i= 0; i < SIZE ; i++ ) {
    cout << arr[i] << "  ";
}
return 0;
}
void addition(int arr[]) {
int i = 0;
for (i = 0; i <= SIZE - 1; i++) {
    arr[i] += 4;
}
}
void subtraction(int arr[] , int _size) {
    int i = 0;
    for (i = 0 ; i <= _size ; i++) {
        arr[i] -= 4;
    }
}
void multiply(int arr[SIZE]) {
    int i = 0;
    for (i = 0 ; i <= SIZE - 1; i++) {
        arr[i] *= 4;
    }
}

