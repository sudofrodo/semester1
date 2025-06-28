#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int num , min_num = 0 , com_num;
do {
cout << "Input the number: ";
cin >> num;
} while (num != -1);
if (num > 0) {
min_num = num;
com_num = num;
};
if (min_num > 1 || com_num < min_num){
    min_num = com_num;
}
cout << "Minimum number " << min_num << endl;
return 0;
}
