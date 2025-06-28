#include <iostream>
#include <iomanip>
const int NUMBER_OF_ROWS = 3;
const int NUMBER_OF_COLUMNS = 3;
using namespace std;
int main() {
int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
int row,col;
int sum;
int largest;
cout << "Enter numbers for matrix." << endl;
//Initializing an array
for (row = 0; row < NUMBER_OF_ROWS; row++) {
for (col = 0; col < NUMBER_OF_COLUMNS; col++) {
matrix[row][col] = 0;
}
}
//Reading data into an array.
for (row = 0; row < NUMBER_OF_ROWS; row++) {
for (col = 0; col < NUMBER_OF_COLUMNS; col++) {
cin >> matrix[row][col];
}
}
//Printing an array
for (row = 0; row < NUMBER_OF_ROWS; row++){
for (col = 0; col < NUMBER_OF_COLUMNS; col++)
cout << setw(5) << matrix[row][col] << " ";
cout << endl;
}
cout << endl << "Sum of each individual row" << endl;
//Sum of each individual row
for (row = 0; row < NUMBER_OF_ROWS; row++){
sum = 0;
for (col = 0; col < NUMBER_OF_COLUMNS; col++)
sum = sum + matrix[row][col];
cout << "Sum of row " << row + 1 << " = " << sum << endl;
}
cout << endl;
cout << "Sum of each individual column" << endl;
for (col = 0; col < NUMBER_OF_COLUMNS; col++) {
sum = 0;
for (row = 0; row < NUMBER_OF_ROWS; row++)
sum = sum + matrix[row][col];
cout << "Sum of column " << col + 1 << " = " << sum << endl;
}
cout << "Largest element in each row" << endl;
for (row = 0; row < NUMBER_OF_ROWS; row++)
{
largest = matrix[row][0]; //Assume that the first element
//of the row is the largest.
for (col = 1; col < NUMBER_OF_COLUMNS; col++)
if (largest < matrix[row][col])
largest = matrix[row][col];
cout << "The largest element in row " << row + 1 << " = "<<
largest << endl;
}
cout << "Largest element in each column" << endl;
for (col = 0 ; col < NUMBER_OF_COLUMNS ; col++) {
    largest = matrix[0][col];
    for (row = 1 ; row < NUMBER_OF_ROWS ; row++) {
        if (largest < matrix[row][col]) {
            largest = matrix[row][col];
        }

    }
    cout << "The largest element in column " << col + 1 << " = " << largest << endl;
}
return 0;
}
