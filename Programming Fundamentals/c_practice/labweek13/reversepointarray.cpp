#include <iostream>
using namespace std;
int main() {
int n;
cout << "Size of your array ?" << endl;
cin >> n;
cout << "Enter numbers " << endl;
double arr[n];
for (int i = 0 ; i < n ; i++) {
    cin >> *(arr + i);
}
cout << "Numbers in reverse order " << endl;
for (int i = n - 1 ; i >= 0 ; i--) {
    cout << *(arr + i) << endl;
}
return 0;
}
