#include <iostream>
using namespace std;
void shapes(char chr , int num);
int main() {
char a;
cout << "Enter character to fill: ";
cin >> a;
int _num;
cout << "Enter square number : ";
cin >> _num;
shapes(a , _num);
return 0;
}
void shapes(char chr , int num) {
int i = 0;
int j = 0;
for (i = 1 ; i <= num ; i++) {
for (j = 1 ; j <= num ; j++ ){
    cout << chr;
}
cout << endl;
}
}

