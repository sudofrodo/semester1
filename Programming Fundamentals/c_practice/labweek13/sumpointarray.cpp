#include <iostream>
using namespace std;
int main() {
int n;
cout << "How many numbers you want to sum ?" << endl;
cin >> n;
cout << "Enter number to sum " << endl;
double arr[n];
for (int i = 0 ; i < n ; i++) {
    cin >> *(arr + i);
}
int sum = 0;
for (int i = 0 ; i < n ; i++) {
   sum += *(arr + i);
}
cout << endl;
cout << "The sum = " << sum << endl;

return 0;
}
