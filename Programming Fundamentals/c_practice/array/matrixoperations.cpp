#include <iostream>
#define ROW_SIZE 3
#define COLUMN_SIZE 3
using namespace std;
int added_matrix[ROW_SIZE][COLUMN_SIZE];
int subtracted_matrix[ROW_SIZE][COLUMN_SIZE];
int mutliplied_matrix[ROW_SIZE][COLUMN_SIZE];
int divided_matrix[ROW_SIZE][COLUMN_SIZE];
void multiply_matrix(int arr[][COLUMN_SIZE] , int arr2[][COLUMN_SIZE]);
void matrix_calculator(int arr[][COLUMN_SIZE] , int arr2[][COLUMN_SIZE] , int ope);
int main() {
int arr[ROW_SIZE][COLUMN_SIZE] = {{1,2,3} ,{4,5,6,} ,{7,8,9}};
int arr2[ROW_SIZE][COLUMN_SIZE] = {{1,2,3} ,{4,5,6,} ,{7,8,9}};

cout << endl;
cout << "Original Matrix" << endl;
int i = 0;
int j = 0;
for (i = 0 ; i < ROW_SIZE ;i++) {
    for (j = 0; j < COLUMN_SIZE ; j++) {
        cout << arr[i][j] << "\t";
    }
     cout << endl;
}
matrix_calculator(arr,arr2,1);
matrix_calculator(arr,arr2,2);
matrix_calculator(arr,arr2,3);
cout << endl;
cout << "Addition of Matrix 1 and Matrix 2" << endl;
for (i = 0 ; i < ROW_SIZE ;i++) {
    for (j = 0; j < COLUMN_SIZE ; j++) {
        cout << added_matrix[i][j] << "\t";
    }
     cout << endl;
}
cout << endl;
cout << "Subtraction of Matrix 1 and Matrix 2" << endl;
for (i = 0 ; i < ROW_SIZE ;i++) {
    for (j = 0; j < COLUMN_SIZE ; j++) {
        cout << subtracted_matrix[i][j] << "\t";
    }
     cout << endl;
}
cout << endl;
cout << "Division of Matrix 1 and Matrix 2" << endl;
for (i = 0 ; i < ROW_SIZE ;i++) {
    for (j = 0; j < COLUMN_SIZE ; j++) {
        cout << divided_matrix[i][j] << "\t";
    }
     cout << endl;
}
cout << "Multiplication of Matrix 1 and Matrix 2" << endl;
for (i = 0 ; i < ROW_SIZE ;i++) {
    for (j = 0; j < COLUMN_SIZE ; j++) {
        cout << mutliplied_matrix[i][j] << "\t";
    }
     cout << endl;
}
multiply_matrix(arr,arr2);
return 0;

}
int i,j;
void matrix_calculator(int arr[][COLUMN_SIZE] , int arr2[][COLUMN_SIZE] , int ope) {
for (i = 0 ; i <= ROW_SIZE ; i++) {
    for (j = 0 ; j <= COLUMN_SIZE ; j++) {
        if (ope == 1) {
        added_matrix[i][j] = arr[i][j] + arr2[i][j];
        }
        if (ope == 2) {
        subtracted_matrix[i][j] = arr[i][j] - arr2[i][j];
        }
        if (ope == 3) {
        divided_matrix[i][j] = arr[i][j] / arr2[i][j];
        }
    }
}
}
void multiply_matrix(int arr[][COLUMN_SIZE] , int arr2[][COLUMN_SIZE]) {
    int col = 0;
    int row = 0;
    int sum = 0;
    for (col = 0 ; col < COLUMN_SIZE;col++) {
        sum = 0;
    for (row = 0 ; row < col ; row++) {
        sum += arr[i][j] * arr2[j][i];
    }
    }
    cout << sum << endl;
}
