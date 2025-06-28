#include <iostream>
using namespace std;
void sorter(int arr[]);
void swap_(int &a , int &b) {
    int hold = a;
    a = b;
    b = hold;
}
int main() {
int arr[] = {5,4,3,2,1};
int i = 0;
cout << "Original Array: ";
for (i = 0 ; i <= 4 ; i++) {
    cout << arr[i] << "  ";
}
sorter(arr);
cout << "Sorted Array: ";
for (i = 0 ; i <= 4 ; i++) {
    cout << arr[i] << "  ";
}
return 0;
}
void sorter(int arr[]) {
int i = 0;
int j = 0;
for (j = 1; j < 5 ; j++) {
for (i = 0 ; i < 4 ; i++) {
if (arr[i] > arr[i + 1]) {
    swap_(arr[i] , arr[i + 1]);
}
}

}
}
