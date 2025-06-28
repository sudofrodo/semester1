#include <iostream>
using namespace std;
int linear_search(int arr[] , int);
int main() {
int arr[] = {5,4,3,2,1};
int i = 0;
cout << "Original Array: ";
for (i = 0 ; i <= 4 ; i++) {
    cout << arr[i] << "  ";
}
cout << endl;
cout << linear_search(arr , 6) << endl;
return 0;
}
int linear_search(int arr[] , int key) {
int i = 0;
for (i = 0 ; i <= 4 ; i++) {
        if (arr[i] == key) {
            return i;
        }
}

return -1;
}

