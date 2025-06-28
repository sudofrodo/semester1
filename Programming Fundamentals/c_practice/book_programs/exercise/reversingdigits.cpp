#include <iostream>
using namespace std;
int reversedigit(int);
int main() {

cout << reversedigit(4321) << endl;
return 0;
}
int reversedigit(int num) {
int i = 0;
int reversenum = 0;
int _num = num;
while (_num != 0) {
    reversenum = (reversenum * 10 ) + _num % 10;
    _num = _num / 10;
}
return reversenum;
}
