#include <iostream>
#define ROW_SIZE 3
#define COLUMN_SIZE 3
using namespace std;
int mutliplied_matrix[3][3];
void multiply_matrix(int arr[][COLUMN_SIZE] , int arr2[][COLUMN_SIZE]);
int main() {
int arr[ROW_SIZE][COLUMN_SIZE] = {{1,2,3} ,{4,5,6,} ,{7,8,9}};
int arr2[ROW_SIZE][COLUMN_SIZE] = {{1,2,3} ,{4,5,6,} ,{7,8,9}};
int array1[1][3] = {1,2,3};
int array2[3][1] = {{1} ,{2} , {3} };

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
multiply_matrix(array2,array1);
cout << "Multiplied matrix" << endl;
for (i = 0 ; i < 3 ; i++) {
    for (j = 0 ; j < 3 ; j++ ) {
        cout << mutliplied_matrix[i][j];
    }
}
return 0;
}
void multiply_matrix(int arr[][1] , int arr2[][3]) {
int i = 0 ;
int j = 0 ;
for (i = 0 ; i < 3 ; i++) {
    for( j = 0 ; j < 3 ; j++) {
        mutliplied_matrix[i][j] = arr[i][j] * arr2[i][j];
    }
}
}
