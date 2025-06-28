#include <iostream>
using namespace std;
int main() {
// simple case
//int a = 0;
//for (a = 10 ; a >= 0; a--){
//    cout << a << endl;
//}
//cout << a << endl;//this will output -1 because tho condition is false, before condition variable is incremented.
//
// now variable is defined inside the loop,
//int b = 0;
//for (int b = 10 ; a >= 0; a--){
//    cout << a << endl;
//}
//cout << b << endl; //this will output zero ,because the variable in loop is different then the variable outside.
// now increment and initiliazation are absent
//int c = 1;
//for ( ; c <=9 ;){
//    cout << c << endl;
//    c++;
//}
//cout << endl;
int r = 0;
int l = 9;
for (;r <=9 ; r++,l--){

    cout <<r <<l<< endl;
}
cout << endl;

//without condition , increment or initilization
//int i = 0;
//for (; ;){
//    if (i <= 10){
//    cout<<i<<endl;
//    i++;
//    } else {
//    break; // if there was no break here , loop would be infinite because there is no condition in loop , and inside the loop is of no concern to outside.
//    }
//}
//cout << i<< endl;
int x;
for (x = 1 ; x <= 10 ;) {
    cout << x << endl;
    ++x;
}
cout << x << endl;
}

