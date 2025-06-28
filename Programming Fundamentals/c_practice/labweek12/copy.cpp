#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_COL = 5;
const int MAX_ROW  = 3;

void _copy(const int x[][MAX_COL], int y[][MAX_COL], int ROW);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;


int arr1[MAX_ROW][MAX_COL] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
int arr2[MAX_ROW][MAX_COL] = {0};
_copy(arr1,arr2,MAX_ROW  );
int i = 0;
int j = 0;
for (i = 0 ; i < MAX_ROW ; i++) {
    for (j = 0 ; j < MAX_COL;j++) {
        cout << setw(3) << setfill(' ')<< arr2[i][j] << "  ";
    }
    cout << endl;
}
}
void _copy(const int x[][MAX_COL], int y[][MAX_COL], int ROW) {
int i = 0;
int j = 0;
for (i = 0 ; i < ROW ; i++) {
    for (j = 0 ; j < MAX_COL;j++) {
        y[i][j] = x[i][j];
    }
}
}

