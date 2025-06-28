#include <iostream>
using namespace std;
#define SIZE 10
void sorter(int arr[]);
int binarysearch(int arr[] , int key);
void swap_(int &a , int &b) {
    int hold = a;
    a = b;
    b = hold;
}
int main() {
int arr[SIZE] = {5,4,3,2,1,6,7,8,9,10};
int i = 0;
cout << "Original Array: ";
for (i = 0 ; i <= SIZE - 1 ; i++) {
    cout << arr[i] << "  ";
}
cout << endl;
int skey;
cout << "Input number to find ";
cin >> skey;


sorter(arr);
cout << endl;
cout << "Sorted Array: ";
for (i = 0 ; i <= SIZE - 1 ; i++) {
    cout << arr[i] << "  ";
}
cout << endl;
cout << "Searched Index ";
cout << binarysearch(arr,skey);
cout << endl;
return 0;
}

void sorter(int arr[]) {
int i = 0;
int j = 0;
for (j = 1; j < SIZE ; j++) {
for (i = 0 ; i < SIZE - 1 ; i++) {
if (arr[i] > arr[i + 1]) {
    swap_(arr[i] , arr[i + 1]);
        }
    }
   }
}
int binarysearch(int arr[] , int key) {
int lower = 0;
int upper = SIZE - 1;
int middle = 0;
while (lower <= upper) {
middle = (lower + upper) / 2;
    if (key == arr[middle]) {
        return middle;
    }
    else if (arr[key] > middle) {
        lower = middle + 1;
    }
    else {
        upper = middle - 1;
    }
}
return -1;
}


