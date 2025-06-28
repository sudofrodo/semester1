#include <iostream>
#include <iomanip>
#define SIZE 10
using namespace std;

int main() {
int n[SIZE] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
size_t i;
int j , k;
cout << "Number        " << "Histogram" << endl << endl;
for (i=0 ; i < SIZE ; i++) {
     j = n[i];
     cout << setw(2) << right << j << "            ";
    for (k = 1 ; k <= j ; k++ ) {
        cout << '*';
    }
    cout << endl;
}
return 0;
}
