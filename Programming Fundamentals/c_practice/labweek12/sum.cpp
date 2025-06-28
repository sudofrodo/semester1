#include <iostream>
#include <iomanip>
using namespace std;
const int ROW_SIZE =  3;
const int COLUMN_SIZE = 3;
void addmatrix(const int X[][COLUMN_SIZE], const int Y[][COLUMN_SIZE], int ROW_SIZE);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
int i = 0 , j = 0;
cout << "Values for first array : " << endl;
int arr1[ROW_SIZE][COLUMN_SIZE];
for (i = 0 ; i < ROW_SIZE ; i++) {
    for (j = 0 ; j < COLUMN_SIZE ; j++) {
        cout << "Array element [" <<i<<"][" << j << "] : ";
        cin >> arr1[i][j];
    }
}
cout << "Values for second array : " << endl;
int arr2[ROW_SIZE][COLUMN_SIZE];
for (i = 0 ; i < ROW_SIZE ; i++) {
    for (j = 0 ; j < COLUMN_SIZE ; j++) {
        cout << "Array element [" <<i<<"][" << j << "] : ";
        cin >> arr2[i][j];
    }
}
addmatrix(arr1,arr2,ROW_SIZE);
}
void addmatrix(const int X[][COLUMN_SIZE], const int Y[][COLUMN_SIZE], int ROW_SIZE) {
    int arr3[ROW_SIZE][COLUMN_SIZE] = {0};
    int i = 0 , j = 0;
    for (i = 0 ; i < ROW_SIZE ; i++) {
        for (j = 0 ; j < COLUMN_SIZE ; j++) {
                    arr3[i][j] = X[i][j] + Y[i][j];
        }
    }
    cout << endl << "Added matrix " << endl;
    for (i = 0 ; i < ROW_SIZE ; i++) {
        for (j = 0 ; j < COLUMN_SIZE ; j++) {
                    cout << arr3[i][j] << "  ";
        }
        cout << endl;
    }
}
