#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_COL= 5;
const int MAX_ROW = 3;
const int MAX_COL2= 3;
const int MAX_ROW2 = 3;
void subarray(const int X[][MAX_COL], int y[][MAX_COL2], int MAX_ROW1, int MAX_ROW2);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
int arr1[MAX_ROW][MAX_COL] = {{1,2,3,4,5} , {6,7,8,9,10} , {11,12,13,14,15}};
cout << "Original Array : " << endl;
int i = 0;
int j = 0;
for (i = 0 ; i < MAX_ROW ; i++) {
    for (j = 0 ; j < MAX_COL;j++) {
        cout << setw(3) << setfill(' ')<< arr1[i][j] << "  ";
    }
    cout << endl;
}
cout << "Sub array " << endl;
int arr2[MAX_ROW2][MAX_COL2] = {};
subarray(arr1,arr2,MAX_ROW,MAX_ROW2);
i = 0;
j = 0;
for (i = 0 ; i < MAX_ROW2 ; i++) {
    for (j = 0 ; j < MAX_COL2;j++) {
        cout << setw(3) << setfill(' ')<< arr2[i][j] << "  ";
    }
    cout << endl;
}
}
void subarray(const int X[][MAX_COL], int Y[][MAX_COL2], int MAX_ROW1, int MAX_ROW2) {
int i = 0 ;
int j = 0;
for (i = 0 ; i < MAX_COL2; i++) {
    for (j = 0 ; j < MAX_ROW2; j++) {
        Y[i][j] = X[i][j];
    }
}

}
