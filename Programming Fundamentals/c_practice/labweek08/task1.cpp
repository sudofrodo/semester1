#include <iostream>
using namespace std;
int main() {
int num = 0;
int pos_count = 0 , neg_count = 0 , zero_count = 0, odd_count = 0 , even_count = 0;
do{
cout << "Number";
cin >> num;
if (num > 0) {
    pos_count++;
}
if (num == 0){
    zero_count++;
}
if (num < 0) {
    neg_count++;
}
if (num % 2 == 0) {
    even_count++;
}
if (num % 2 != 0) {
    odd_count++;
}
} while(num != 999);
cout << "# of positive numbers : " << pos_count;
cout << "# of negative numbers : " << neg_count;
cout << "# of even numbers : " << even_count;
cout << "# of odd numbers : " << odd_count;
cout << "# of zeros : " << zero_count;
return 0;
}
