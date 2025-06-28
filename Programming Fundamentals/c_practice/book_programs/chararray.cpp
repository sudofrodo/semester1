#include <iostream>
#include <iomanip>
#define SIZE 10
using namespace std;
int main() {
char string1[SIZE];
//char string2[] = "string literal";
size_t i;
cout << "Enter characters : " << endl;
for (i = 0; i < SIZE - 1 ; i++ ){
    cout << i << " ";
    cin >> string1[i];
}
cout << string1 << endl;
string star = string1;
cout << star;
return 0;
}
