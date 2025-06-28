#include <iomanip>
#include <iostream>
#define STUDENT 10
using namespace std;
int main() {
cout << "Arrays" << endl;
//int arr[5];
//float marks[3] = { 1.3, 2.5, 3.6};
//for (int j = 0 ; j <= 2 ; j++) {
//    cout << marks[j] << endl;
//}
//int sum = 0;
//int i = 0;
//cout <<  "Put in the values for arrays." << endl;
//for (i = 1 ; i <= 5 ; i++) {
//    cout << i << " element: ";
//    cin >> arr[i];
//}
//cout << setw(30) << setfill('=') << '=' << endl;
//for (i = 1 ; i <= 5 ; i++) {
//    sum += arr[i];
//}
//for (i = 1 ; i <= 5 ; i++) {
//    cout << i << " element = ";
//    cout << arr[i] << endl;
//
//}
//cout << endl;
//cout << "Sum = " << sum;
int i , j = 0;
float stu_arr[STUDENT] = {};
for(i = 0 ; i < STUDENT; i++) {
    for(j = 0 ; j < STUDENT; j=j+5) {
    stu_arr[i] = j;
    }
}
for(int j = 0 ; j < STUDENT ; j++) {
    cout << stu_arr[j] << endl;
}
return 0;
}
