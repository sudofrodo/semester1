#include <iostream>
#define row_size 4
#define column_size 4
using namespace std;
int main() {
int arr[row_size][column_size] = {{1,0,1,0} ,{1,3,4,5}};
cout << endl;
int i = 0;
int j = 0;
for (i = 0 ; i < row_size ;i++) {
    for (j = 0; j < column_size ; j++) {
        cout << arr[i][j] << "\t";
    }
     cout << endl;
}
return 0;
}
