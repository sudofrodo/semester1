#include <iostream>
using namespace std;
void cubeByReference(int *);
void swap(int *i , int *j) {
int temp = *i;
*i = *j;
*j = temp;
}
int main() {

//char name[] = "COMSATS";
//char *
//ptr = name;
//for (; *ptr != '\0' ; ptr++) {
//    cout << ptr << endl;
//}

//int m = 10 , n = 5;
//int *ptr_m , *ptr_n;
//ptr_m = &m;
//ptr_n = &n;
//cout << ptr_m << "  " << ptr_n << endl; // addresses of m and n
//*ptr_m = *ptr_m + *ptr_n;
//*ptr_n = *ptr_m - *ptr_n;
//cout << m << "  " << *ptr_m << "   " << n << "  " << *ptr_n;
// m  15  n  10

//pass by reference / pointer

//int number = 5;
//cout << "The original value of number is " << number;
//cubeByReference( &number);
//cout << endl <<"The new value of number is " << number;
//return 0;
//}
//void cubeByReference(int *nptr) {
//    *nptr = *nptr * *nptr * *nptr;
//}

// swap by pointers
//int x = 10 , y = 20;
//swap(&x , &y);
//cout << "x  " << x << " y  " << y << endl;

//display address of each element of an array

//double arr[3];
//double *ptr;
//cout << "Displaying address using address of operator: " << endl;
//for (int i = 0 ; i < 3; ++i) {
//    cout << "&arr[" << i << "] = " << &arr[i] << endl;
//
//}
//ptr = arr;
//cout << "\nDisplaying addresses using pointers : " << endl;
//for (int i = 0 ; i < 3 ; ++i) {
//    cout << "ptr + " << i << " = " << ptr + i << endl;
//}

//input and display through pointers
double arr[5];
cout << "Enter 5 numbers : " << endl;
for (int i = 0; i < 5 ; ++i) {
    cin >> *(arr + i);
}
cout << "Displaying data: " << endl;
for (int i = 0; i < 5 ; ++i) {
    cout << *(arr + i) << endl;
}
return 0;
}
